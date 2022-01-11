import sys

mem = set()
for line in sys.stdin:
    tokens = line.split()
    ret = []
    for token in tokens:
        if token.lower() in mem:
            ret.append(".")
        else:
            ret.append(token)
            mem.add(token.lower())
    print(" ".join(ret))
    