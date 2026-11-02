#!/usr/bin/env python3
"""Build the exercises book.

For every chapter source file  data/chNN.txt  this script:
  1. parses the exercises (statement, steps, flowchart DSL, C code),
  2. writes code/chNN/exMM.c, compiles it (gcc -Wall -Wextra -Werror),
     runs it and stores the real output in code/chNN/exMM.out,
  3. checks that no predefined helper function is used,
  4. generates gen/chNN.tex (exercise pages + TikZ flowcharts).

Usage:  python3 tools/build.py [chapter numbers...]
"""
import math
import os
import re
import shutil
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from cscan import single_letter_ids  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA = os.path.join(ROOT, "data")
CODE = os.path.join(ROOT, "code")
GEN = os.path.join(ROOT, "gen")

LEVELS = {"easy": 1, "medium": 2, "hard": 3}
DOMAINS = {"ec": "تجارة إلكترونية", "ds": "علم البيانات"}
EXPECTED = {1: 10, 2: 30, 3: 10}

FORBIDDEN = (
    "strlen strcpy strncpy strcat strncat strcmp strncmp strchr strrchr strstr "
    "strtok strdup memcpy memmove memset memcmp sqrt pow fabs abs labs floor "
    "ceil round trunc fmod exp log log10 sin cos tan qsort bsearch atoi atol "
    "atof strtol strtod toupper tolower isdigit isalpha isalnum isspace isupper "
    "islower rand srand sprintf snprintf sscanf fmax fmin realloc calloc"
).split()
FORBIDDEN_RE = re.compile(r"\b(" + "|".join(FORBIDDEN) + r")\s*\(")
ALLOWED_INCLUDES = {"stdio.h", "stdlib.h"}
STDLIB_CHAPTERS = {10, 11, 12, 13}

AR_RE = re.compile(r"[\u0600-\u06FF]")


# ----------------------------------------------------------------------
# Text helpers
# ----------------------------------------------------------------------
def esc_code(s):
    out = []
    for ch in s:
        if ch == "\\":
            out.append(r"\textbackslash{}")
        elif ch in "{}%#&_$":
            out.append("\\" + ch)
        elif ch == "^":
            out.append(r"\textasciicircum{}")
        elif ch == "~":
            out.append(r"\textasciitilde{}")
        else:
            out.append(ch)
    return "".join(out)


def esc_text(s):
    out = []
    for ch in s:
        if ch in "%#&_$":
            out.append("\\" + ch)
        elif ch == "^":
            out.append(r"\textasciicircum{}")
        elif ch == "~":
            out.append(r"\textasciitilde{}")
        else:
            out.append(ch)
    return "".join(out)


RUN = r"[A-Za-z0-9][A-Za-z0-9_.,%+\-*/=<>:'\[\]]*"
RUN_RE = re.compile(RUN + r"(?:[ ]+" + RUN + r")*")


def wrap_runs(s, cmd):
    """Wrap ASCII runs (Latin words, numbers) of an Arabic text in cmd{}."""
    res, pos = [], 0
    for m in RUN_RE.finditer(s):
        run = m.group(0)
        tail = ""
        while run and run[-1] in ".,:'":
            tail = run[-1] + tail
            run = run[:-1]
        res.append(esc_text(s[pos:m.start()]))
        res.append(cmd + "{" + esc_code(run) + "}" + esc_text(tail))
        pos = m.end()
    res.append(esc_text(s[pos:]))
    return "".join(res)


def bold(s):
    return re.sub(r"\*\*(.+?)\*\*", r"\\textbf{\1}", s)


def text_to_tex(s, codecmd=r"\code"):
    """Arabic text with `inline code` and **bold**."""
    parts = s.split("`")
    out = []
    for i, p in enumerate(parts):
        if i % 2 == 1 and len(p) > 42 and codecmd == r"\code":
            # too long to stay inline (cannot wrap): own centered line
            out.append(r"\par{\centering\small" + codecmd + "{" + esc_code(p) + r"}\par}")
        elif i % 2 == 1:
            out.append(codecmd + "{" + esc_code(p) + "}")
        else:
            out.append(bold(wrap_runs(p, r"\en")))
    return "".join(out)


def is_code(s):
    return not AR_RE.search(s) and "`" not in s


def code_pieces(s):
    return [p.strip() for p in s.strip().split(" ; ")]


def flow_text(s):
    s = s.strip()
    if is_code(s):
        return r"\\".join(r"\fc{" + esc_code(p) + "}" for p in code_pieces(s))
    return text_to_tex(s, r"\fc")


def visible_len(s):
    return len(s.replace("`", "").replace("**", ""))


# ----------------------------------------------------------------------
# Flowchart layout (absolute coordinates, in cm)
# ----------------------------------------------------------------------
G = 0.5          # vertical gap between blocks
CH = 0.2         # average char width (cm)
LH = 0.46        # line height (cm)


class Ctx:
    def __init__(self):
        self.n = 0
        self.lines = []

    def name(self, p):
        self.n += 1
        return f"{p}{self.n}"

    def add(self, s):
        self.lines.append(s)


def fmt(v):
    return f"{v:.2f}"


class Simple:
    MAXW = {"do": 4.4, "call": 4.4, "in": 4.0, "out": 4.0, "term": 4.0}

    def __init__(self, kind, text):
        self.kind, self.text = kind, text
        lab = 6 if kind in ("in", "out") else 0
        maxw = self.MAXW[kind]
        if is_code(text):
            pieces = code_pieces(text)
            est = (max(len(p) for p in pieces) + lab) * CH + 0.3
            tw = max(est, 0.8)
            lines = len(pieces)
        else:
            est = (visible_len(text) + lab) * CH + 0.3
            tw = min(max(est, 0.8), maxw)
            lines = max(1, math.ceil(est / maxw))
        self.tw = tw
        self.h = lines * LH + 0.32
        extra = 0.7 * self.h if kind in ("in", "out") else 0.0
        self.w = tw + 0.3 + extra
        self.left = self.right = self.w / 2
        self.top_point = False

    def emit(self, ctx, x, y):
        nm = ctx.name("n")
        style = {"do": "fproc", "call": "fcall", "in": "fio", "out": "fio",
                 "term": "fterm"}[self.kind]
        txt = flow_text(self.text)
        if self.kind == "in":
            txt = r"\textbf{اقرأ}\ " + txt
        elif self.kind == "out":
            txt = r"\textbf{اكتب}\ " + txt
        if self.kind == "term":
            ctx.add(f"\\node[{style}] ({nm}) at ({fmt(x)},{fmt(y - self.h / 2)}) {{{txt}}};")
        else:
            ctx.add(f"\\node[{style}, text width={fmt(self.tw)}cm] ({nm}) at "
                    f"({fmt(x)},{fmt(y - self.h / 2)}) {{{txt}}};")
        self.top, self.bot = f"({nm}.north)", f"({nm}.south)"
        self.bot_point = False


class Seq:
    def __init__(self, blocks):
        self.blocks = blocks
        self.h = sum(b.h for b in blocks) + G * (len(blocks) - 1)
        self.left = max(b.left for b in blocks)
        self.right = max(b.right for b in blocks)
        self.top_point = blocks[0].top_point

    def emit(self, ctx, x, y):
        prev = None
        for b in self.blocks:
            b.emit(ctx, x, y)
            if prev is not None:
                st = "fline" if b.top_point else "sahm"
                ctx.add(f"\\draw[{st}] {prev.bot} -- {b.top};")
            y -= b.h + G
            prev = b
        self.top, self.bot = self.blocks[0].top, self.blocks[-1].bot
        self.bot_point = self.blocks[-1].bot_point


class Diamond:
    def __init__(self, text):
        self.text = text
        n = visible_len(text)
        maxw = 3.0
        est = n * CH + 0.25
        if is_code(text):
            self.tw = max(est, 0.8)
            lines = len(code_pieces(text))
        else:
            self.tw = min(max(est, 0.8), maxw)
            lines = max(1, math.ceil(est / maxw))
        w = self.tw + 0.25
        h = lines * LH + 0.15
        a = 2.2
        self.W = w + h * a
        self.H = h + w / a

    def emit(self, ctx, x, yc):
        nm = ctx.name("d")
        ctx.add(f"\\node[fdec, text width={fmt(self.tw)}cm] ({nm}) at "
                f"({fmt(x)},{fmt(yc)}) {{{flow_text(self.text)}}};")
        return nm


def yes_lbl(ctx, at, anchor="north west", shift="xshift=3pt,yshift=-1pt"):
    ctx.add(f"\\node[flbl, anchor={anchor}] at ([{shift}]{at}) {{نعم}};")


def no_lbl(ctx, at, anchor="south west", shift="xshift=2pt,yshift=1pt"):
    ctx.add(f"\\node[flbl, anchor={anchor}] at ([{shift}]{at}) {{لا}};")


class If:
    def __init__(self, cond, then, other=None):
        self.d = Diamond(cond)
        self.then, self.other = then, other
        hd, wd = self.d.H, self.d.W
        self.top_point = False
        if other is None:
            self.xr = max(wd / 2, then.right) + 0.5
            self.h = hd + G + then.h + 0.6 * G
            self.left = max(wd / 2, then.left)
            self.right = self.xr + 0.3
        else:
            self.dr = max(wd / 2 + 0.25, then.left + 0.35)
            self.dl = max(wd / 2 + 0.25, other.right + 0.35)
            self.h = hd + 0.6 * G + max(then.h, other.h) + 0.6 * G
            self.right = self.dr + then.right
            self.left = self.dl + other.left

    def emit(self, ctx, x, y):
        hd = self.d.H
        d = self.d.emit(ctx, x, y - hd / 2)
        m = ctx.name("m")
        if self.other is None:
            y1 = y - hd - G
            self.then.emit(ctx, x, y1)
            ym = y1 - self.then.h - 0.6 * G
            ctx.add(f"\\coordinate ({m}) at ({fmt(x)},{fmt(ym)});")
            st = "fline" if self.then.top_point else "sahm"
            ctx.add(f"\\draw[{st}] ({d}.south) -- {self.then.top};")
            yes_lbl(ctx, f"{d}.south")
            ctx.add(f"\\draw[fline] {self.then.bot} -- ({m});")
            xr = x + self.xr
            ctx.add(f"\\draw[sahm] ({d}.east) -- ({fmt(xr)},{fmt(y - hd / 2)}) -- "
                    f"({fmt(xr)},{fmt(ym)}) -- ({m});")
            no_lbl(ctx, f"{d}.east")
        else:
            y1 = y - hd - 0.6 * G
            xt, xe = x + self.dr, x - self.dl
            self.then.emit(ctx, xt, y1)
            self.other.emit(ctx, xe, y1)
            ym = y1 - max(self.then.h, self.other.h) - 0.6 * G
            ctx.add(f"\\coordinate ({m}) at ({fmt(x)},{fmt(ym)});")
            for blk, xx, side in ((self.then, xt, "east"), (self.other, xe, "west")):
                st = "fline" if blk.top_point else "sahm"
                ctx.add(f"\\draw[{st}] ({d}.{side}) -| {blk.top};")
                ctx.add(f"\\draw[sahm] {blk.bot} |- ({m});")
            yes_lbl(ctx, f"{d}.east", "south west", "xshift=2pt,yshift=1pt")
            no_lbl(ctx, f"{d}.west", "south east", "xshift=-2pt,yshift=1pt")
        self.top = f"({d}.north)"
        self.bot = f"({m})"
        self.bot_point = True


class While:
    def __init__(self, cond, body):
        self.d = Diamond(cond)
        self.body = body
        hd, wd = self.d.H, self.d.W
        self.xl = max(wd / 2, body.left) + 0.45
        self.xr = max(wd / 2, body.right) + 0.45
        self.h = 0.35 + hd + G + body.h + 0.35 + 0.45
        self.left = self.xl + 0.1
        self.right = self.xr + 0.3
        self.top_point = True

    def emit(self, ctx, x, y):
        hd = self.d.H
        t, j, e = ctx.name("t"), ctx.name("j"), ctx.name("e")
        ctx.add(f"\\coordinate ({t}) at ({fmt(x)},{fmt(y)});")
        ctx.add(f"\\coordinate ({j}) at ({fmt(x)},{fmt(y - 0.2)});")
        d = self.d.emit(ctx, x, y - 0.35 - hd / 2)
        ctx.add(f"\\draw[sahm] ({t}) -- ({d}.north);")
        y1 = y - 0.35 - hd - G
        self.body.emit(ctx, x, y1)
        st = "fline" if self.body.top_point else "sahm"
        ctx.add(f"\\draw[{st}] ({d}.south) -- {self.body.top};")
        yes_lbl(ctx, f"{d}.south")
        yb = y1 - self.body.h
        xl, xr = x - self.xl, x + self.xr
        ctx.add(f"\\draw[sahm] {self.body.bot} -- ({fmt(x)},{fmt(yb - 0.35)}) -- "
                f"({fmt(xl)},{fmt(yb - 0.35)}) -- ({fmt(xl)},{fmt(y - 0.2)}) -- ({j});")
        ye = yb - 0.35 - 0.45
        ctx.add(f"\\coordinate ({e}) at ({fmt(x)},{fmt(ye)});")
        ctx.add(f"\\draw[fline] ({d}.east) -- ({fmt(xr)},{fmt(y - 0.35 - hd / 2)}) -- "
                f"({fmt(xr)},{fmt(ye)}) -- ({e});")
        no_lbl(ctx, f"{d}.east")
        self.top, self.bot, self.bot_point = f"({t})", f"({e})", True


class DoWhile:
    def __init__(self, cond, body):
        self.d = Diamond(cond)
        self.body = body
        hd, wd = self.d.H, self.d.W
        self.xl = max(wd / 2, body.left) + 0.45
        self.h = 0.3 + body.h + G + hd
        self.left = self.xl + 0.1
        self.right = max(wd / 2, body.right) + 0.2
        self.top_point = True

    def emit(self, ctx, x, y):
        hd = self.d.H
        t, j = ctx.name("t"), ctx.name("j")
        ctx.add(f"\\coordinate ({t}) at ({fmt(x)},{fmt(y)});")
        ctx.add(f"\\coordinate ({j}) at ({fmt(x)},{fmt(y - 0.15)});")
        self.body.emit(ctx, x, y - 0.3)
        st = "fline" if self.body.top_point else "sahm"
        ctx.add(f"\\draw[{st}] ({t}) -- {self.body.top};")
        yb = y - 0.3 - self.body.h
        d = self.d.emit(ctx, x, yb - G - hd / 2)
        ctx.add(f"\\draw[sahm] {self.body.bot} -- ({d}.north);")
        xl = x - self.xl
        ctx.add(f"\\draw[sahm] ({d}.west) -- ({fmt(xl)},{fmt(yb - G - hd / 2)}) -- "
                f"({fmt(xl)},{fmt(y - 0.15)}) -- ({j});")
        yes_lbl(ctx, f"{d}.west", "south east", "xshift=-2pt,yshift=1pt")
        no_lbl(ctx, f"{d}.south", "north west", "xshift=3pt,yshift=-1pt")
        self.top, self.bot, self.bot_point = f"({t})", f"({d}.south)", False


def parse_flow(lines):
    """Indentation-based DSL -> block tree."""
    items = []
    for raw in lines:
        if not raw.strip():
            continue
        ind = (len(raw) - len(raw.lstrip(" "))) // 2
        key, _, val = raw.strip().partition(":")
        items.append((ind, key.strip(), val.strip()))

    start_txt, end_txt = "بداية", "نهاية"
    body = []
    for it in items:
        if it[0] == 0 and it[1] == "start":
            start_txt = it[2]
        elif it[0] == 0 and it[1] == "end":
            end_txt = it[2]
        else:
            body.append(it)

    pos = 0

    def block(level):
        nonlocal pos
        res = []
        while pos < len(body) and body[pos][0] >= level:
            ind, key, val = body[pos]
            if ind > level:
                raise ValueError(f"bad indentation near '{key}: {val}'")
            pos += 1
            if key in ("do", "in", "out", "call"):
                res.append(Simple(key, val))
            elif key == "if":
                then = block(level + 1)
                other = None
                if pos < len(body) and body[pos][0] == level and body[pos][1] == "else":
                    pos += 1
                    other = block(level + 1)
                res.append(If(val, then, other))
            elif key == "while":
                res.append(While(val, block(level + 1)))
            elif key == "dowhile":
                res.append(DoWhile(val, block(level + 1)))
            elif key == "for":
                parts = [p.strip() for p in val.split(" ; ")]
                if len(parts) != 3:
                    raise ValueError(f"for needs 'init ; cond ; step': {val}")
                inner = block(level + 1)
                inner_blocks = inner.blocks + [Simple("do", parts[2])]
                res.append(Seq([Simple("do", parts[0]),
                                While(parts[1], Seq(inner_blocks))]))
            else:
                raise ValueError(f"unknown flow key '{key}'")
        if not res:
            raise ValueError("empty block in flowchart")
        return Seq(res)

    main = block(0)
    return Seq([Simple("term", start_txt)] + main.blocks + [Simple("term", end_txt)])


def flow_tikz(lines):
    tree = parse_flow(lines)
    ctx = Ctx()
    tree.emit(ctx, 0.0, 0.0)
    body = "\n".join(ctx.lines)
    return ("\\begin{flowbox}\n\\adjustbox{max width=\\linewidth, "
            "max totalheight=0.78\\textheight}{%\n\\begin{tikzpicture}\n"
            + body + "\n\\end{tikzpicture}}\n\\end{flowbox}\n")


# ----------------------------------------------------------------------
# Exercise file parsing
# ----------------------------------------------------------------------
def parse_chapter(path):
    exs, cur, sec = [], None, None
    with open(path, encoding="utf-8") as f:
        for line in f:
            line = line.rstrip("\n")
            if line.startswith("@@"):
                cur = {"meta": {}, "statement": [], "steps": [], "flow": [],
                       "code": [], "stdin": []}
                exs.append(cur)
                sec = "meta"
                continue
            if cur is None:
                continue
            m = re.match(r"^@ (\w+)\s*$", line)
            if m:
                sec = m.group(1)
                if sec not in cur:
                    raise ValueError(f"{path}: unknown section {sec}")
                continue
            if sec == "meta":
                if line.strip():
                    k, _, v = line.partition(":")
                    cur["meta"][k.strip()] = v.strip()
            else:
                cur[sec].append(line)
    return exs


def c_to_listing(code):
    """Replace Arabic // comments with escaped LaTeX (rendered RTL, red)."""
    out = []
    for line in code.split("\n"):
        idx = find_comment(line)
        if idx >= 0 and AR_RE.search(line[idx:]):
            txt = line[idx + 2:].strip()
            out.append(line[:idx] + "(*@\\cmt{" + wrap_runs(txt, r"\cen") + "}@*)")
        else:
            out.append(line)
    return "\n".join(out)


def find_comment(line):
    in_str, in_chr, i = False, False, 0
    while i < len(line) - 1:
        c = line[i]
        if c == "\\" and (in_str or in_chr):
            i += 2
            continue
        if c == '"' and not in_chr:
            in_str = not in_str
        elif c == "'" and not in_str:
            in_chr = not in_chr
        elif not in_str and not in_chr and line[i:i + 2] == "//":
            return i
        i += 1
    return -1


def code_size(code):
    """Pick a listing font size from the widest line (Arabic comment counted)."""
    width = 0
    for line in code.split("\n"):
        width = max(width, len(line.expandtabs(4)))
    if width > 92:
        return r"\scriptsize"
    if width > 78:
        return r"\footnotesize"
    return r"\small"


def check_code(ch, num, code):
    errs = []
    for inc in re.findall(r"#include\s*<([^>]+)>", code):
        if inc not in ALLOWED_INCLUDES or (inc == "stdlib.h" and ch not in STDLIB_CHAPTERS):
            errs.append(f"include <{inc}> not allowed")
    stripped = "\n".join(l[:find_comment(l)] if find_comment(l) >= 0 else l
                         for l in code.split("\n"))
    stripped = re.sub(r'"(\\.|[^"\\])*"', '""', stripped)
    for m in FORBIDDEN_RE.finditer(stripped):
        errs.append(f"predefined function {m.group(1)}() used")
    short = single_letter_ids(code)
    if short:
        errs.append("one-letter identifiers: " + " ".join(sorted(short)))
    return errs


def compile_run(ch, num, code, stdin, cdir, workdir):
    base = os.path.join(cdir, f"ex{num:02d}")
    with open(base + ".c", "w", encoding="utf-8") as f:
        f.write(code)
    exe = os.path.join(workdir, f"ex{num:02d}")
    r = subprocess.run(["gcc", "-std=c99", "-Wall", "-Wextra", "-Werror",
                        "-pedantic", base + ".c", "-o", exe],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return None, "COMPILE ERROR\n" + r.stderr
    try:
        r = subprocess.run([exe], input=stdin, capture_output=True, text=True,
                           timeout=10, cwd=workdir)
    except subprocess.TimeoutExpired:
        return None, "TIMEOUT"
    if r.returncode != 0:
        return None, f"exit code {r.returncode}\n{r.stdout}\n{r.stderr}"
    return r.stdout, None


def build_chapter(ch):
    exs = []
    for fn in sorted(os.listdir(DATA)):
        if re.match(rf"ch{ch:02d}[a-z]?\.txt$", fn):
            exs += parse_chapter(os.path.join(DATA, fn))
    cdir = os.path.join(CODE, f"ch{ch:02d}")
    os.makedirs(cdir, exist_ok=True)
    os.makedirs(GEN, exist_ok=True)
    counts = {1: 0, 2: 0, 3: 0}
    problems = []
    tex = []
    workdir = tempfile.mkdtemp(prefix=f"exbook{ch}_")
    last_level = 1
    for num, ex in enumerate(exs, 1):
        meta = ex["meta"]
        tag = f"ch{ch:02d}/ex{num:02d} ({meta.get('title', '?')})"
        lv = LEVELS.get(meta.get("level", ""))
        if lv is None:
            problems.append(f"{tag}: bad level")
            continue
        if lv < last_level:
            problems.append(f"{tag}: levels must go easy -> medium -> hard")
        last_level = lv
        counts[lv] += 1
        code = "\n".join(ex["code"]).strip("\n") + "\n"
        stdin = "\n".join(ex["stdin"]).strip("\n")
        stdin = stdin + "\n" if stdin else ""
        for e in check_code(ch, num, code):
            problems.append(f"{tag}: {e}")
        out, err = compile_run(ch, num, code, stdin, cdir, workdir)
        if err:
            problems.append(f"{tag}: {err}")
            out = "(error)\n"
        nlines = out.count("\n")
        if nlines > 30:
            problems.append(f"{tag}: output has {nlines} lines (max 30)")
        base = os.path.join(cdir, f"ex{num:02d}")
        with open(base + ".out", "w", encoding="utf-8") as f:
            f.write(out if out.strip() else "(no output)\n")
        with open(base + ".lst", "w", encoding="utf-8") as f:
            f.write(c_to_listing(code))
        if stdin:
            with open(base + ".in", "w", encoding="utf-8") as f:
                f.write(stdin)
        try:
            flow = flow_tikz(ex["flow"])
        except ValueError as e:
            problems.append(f"{tag}: flow: {e}")
            flow = ""
        rel = f"code/ch{ch:02d}/ex{num:02d}"
        statement = "\n".join(ex["statement"]).strip()
        st_tex = "\n\n".join(text_to_tex(p.replace("\n", " "))
                             for p in re.split(r"\n\s*\n", statement))
        steps = [s.strip()[1:].strip() for s in ex["steps"] if s.strip().startswith("-")]
        dom = DOMAINS.get(meta.get("domain", "ec"), "")
        t = [f"\\exhead{{{ch}.{num}}}{{{lv}}}{{{text_to_tex(meta.get('title', ''))}}}"
             f"{{\\faTag\\ {dom}}}",
             "\\begin{statement}", st_tex, "\\end{statement}",
             "\\parthead{\\faListOl}{خطوات الحل}",
             "\\begin{stepsbox}\\begin{enumerate}"]
        t += ["\\item " + text_to_tex(s) for s in steps]
        t += ["\\end{enumerate}\\end{stepsbox}",
              "\\parthead{\\faCode}{البرنامج بلغة \\en{C}}",
              f"\\ccode[{code_size(code)}]{{{rel}.lst}}"]
        if stdin:
            t += ["\\parthead{\\faKeyboard}{المدخلات}", f"\\cout{{{rel}.in}}"]
        t += ["\\parthead{\\faTerminal}{نتيجة التنفيذ}", f"\\cout{{{rel}.out}}",
              "\\parthead{\\faProjectDiagram}{المخطط الانسيابي \\en{(Organigramme)}}",
              flow]
        tex.append("\n".join(t))
    shutil.rmtree(workdir, ignore_errors=True)
    lvl_title = {1: "التمارين السهلة", 2: "التمارين المتوسطة", 3: "التمارين الصعبة"}
    # insert level section headings
    final, cur = [], 0
    idx = 0
    for num, ex in enumerate(exs, 1):
        lv = LEVELS.get(ex["meta"].get("level", ""), 0)
        if lv != cur and lv:
            final.append(f"\\clearpage\n\\levelsection{{{lv}}}{{{lvl_title[lv]}}}")
            cur = lv
        final.append(tex[idx])
        idx += 1
    with open(os.path.join(GEN, f"ch{ch:02d}.tex"), "w", encoding="utf-8") as f:
        f.write("\n\n".join(final) + "\n")
    doms = {"ec": 0, "ds": 0}
    for ex in exs:
        d = ex["meta"].get("domain", "ec")
        doms[d] = doms.get(d, 0) + 1
    with open(os.path.join(GEN, f"ch{ch:02d}_stats.tex"), "w", encoding="utf-8") as f:
        f.write(f"\\chapstats{{{counts[1]}}}{{{counts[2]}}}{{{counts[3]}}}"
                f"{{{doms['ec']}}}{{{doms['ds']}}}\n")
    for lv, n in counts.items():
        if n != EXPECTED[lv]:
            problems.append(f"ch{ch:02d}: {n} exercises of level {lv} (expected {EXPECTED[lv]})")
    return len(exs), problems


def main():
    chs = [int(a) for a in sys.argv[1:]] or [
        int(f[2:4]) for f in sorted(os.listdir(DATA)) if re.match(r"ch\d\d[a-z]?\.txt", f)]
    chs = sorted(set(chs))
    total_problems = 0
    for ch in chs:
        n, probs = build_chapter(ch)
        print(f"chapter {ch}: {n} exercises, {len(probs)} problem(s)")
        for p in probs:
            print("   -", p)
        total_problems += len(probs)
    sys.exit(1 if total_problems else 0)


if __name__ == "__main__":
    main()
