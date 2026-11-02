"""Helpers: find / rename identifiers in C code, skipping string and char literals."""
import re

ID_RE = re.compile(r"(?<![A-Za-z0-9_.])[A-Za-z_][A-Za-z0-9_]*")


def split_code(code):
    """Yield (is_literal, text) chunks; literals = "..." and '...'."""
    out, i, n, start = [], 0, len(code), 0
    while i < n:
        c = code[i]
        if c in "\"'":
            if start < i:
                out.append((False, code[start:i]))
            j = i + 1
            while j < n and code[j] != c:
                j += 2 if code[j] == "\\" else 1
            out.append((True, code[i:j + 1]))
            i = start = j + 1
            continue
        if code.startswith("//", i):          # comment: keep scanning, may hold quotes
            k = code.find("\n", i)
            k = n if k < 0 else k
            out.append((False, code[start:k]))
            i = start = k
            continue
        i += 1
    if start < n:
        out.append((False, code[start:]))
    return out


def rename_code(code, mapping):
    res = []
    for lit, txt in split_code(code):
        if lit:
            res.append(txt)
        else:
            res.append("\n".join(
                l if l.lstrip().startswith("#include") else
                ID_RE.sub(lambda m: mapping.get(m.group(0), m.group(0)), l)
                for l in txt.split("\n")))
    return "".join(res)


def single_letter_ids(code):
    found = set()
    for lit, txt in split_code(code):
        if lit:
            continue
        lines = []
        for line in txt.split("\n"):
            if line.lstrip().startswith("#include"):
                continue
            k = line.find("//")
            lines.append(line if k < 0 else line[:k])
        for m in ID_RE.finditer("\n".join(lines)):
            if len(m.group(0)) == 1:
                found.add(m.group(0))
    return found


def rename_text(text, mapping, backticks_only):
    """Rename inside `code` spans; also in plain parts unless backticks_only.
    Quoted "..." parts are left untouched."""
    parts = text.split("`")
    out = []
    for i, p in enumerate(parts):
        if i % 2 == 1 or not backticks_only:
            segs = re.split(r'("[^"]*")', p)
            p = "".join(s if s.startswith('"') else
                        ID_RE.sub(lambda m: mapping.get(m.group(0), m.group(0)), s)
                        for s in segs)
        out.append(p)
    return "`".join(out)
