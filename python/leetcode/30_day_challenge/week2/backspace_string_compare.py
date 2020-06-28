def backspaceCompare(s: str, t: str) -> bool:
    if process(s) == process(t):
        return True
    return False

def process(s: str):
    ret = []
    for c in s:
        if c == '#' and ret:
            ret.pop()
        if c != '#':
            ret.append(c)
    return ''.join(ret)

print(backspaceCompare("ab##", "c#d#"))