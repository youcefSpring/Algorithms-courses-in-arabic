"""One-time migration: apply tools/renames.txt to the data files."""
import os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from cscan import rename_code, rename_text

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
maps = {}
for line in open(os.path.join(ROOT, "tools/renames.txt"), encoding="utf-8"):
    if ":" not in line:
        continue
    key, _, rest = line.partition(":")
    ch, ex = map(int, key.split("."))
    maps[(ch, ex)] = dict(p.split("=") for p in rest.split())

chapters = sorted({c for c, _ in maps})
for ch in chapters:
    files = sorted(f for f in os.listdir(os.path.join(ROOT, "data"))
                   if re.match(rf"ch{ch:02d}[a-z]?\.txt$", f))
    num = 0
    for fn in files:
        path = os.path.join(ROOT, "data", fn)
        lines = open(path, encoding="utf-8").read().split("\n")
        out, sec, buf = [], None, []

        def flush():
            m = maps.get((ch, num), {})
            if sec == "code":
                out.extend(rename_code("\n".join(buf), m).split("\n"))
            elif sec in ("flow", "steps"):
                out.extend(rename_text(l, m, False) for l in buf)
            elif sec == "statement":
                out.extend(rename_text(l, m, True) for l in buf)
            else:
                out.extend(buf)
            buf.clear()

        for line in lines:
            if line.startswith("@@"):
                flush(); num += 1; sec = "meta"; out.append(line); continue
            mm = re.match(r"^@ (\w+)\s*$", line)
            if mm:
                flush(); sec = mm.group(1); out.append(line); continue
            buf.append(line)
        flush()
        open(path, "w", encoding="utf-8").write("\n".join(out))
print("migrated", chapters)
