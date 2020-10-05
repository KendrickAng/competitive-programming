import sys
from collections import defaultdict

def solve(lineArr):
    if not lineArr:
        return -1
    mem = defaultdict(int)
    candidates = []
    for match in lineArr:
        mem[match] += 1
        if mem[match] == 2 or mem[match] == 4:
            candidates.append(match)
    if len(candidates) < 2:
        return -1
    candidates.sort(reverse=True)
    return candidates[0] * 2 + candidates[1] * 2

ret = []
for line in sys.stdin:
    lineArr = list(map(int, line.split()))
    ret.append(solve(lineArr))

with open('output2.txt', 'w') as file:
    file.writelines(' '.join(map(str, ret)))