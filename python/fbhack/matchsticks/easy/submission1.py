import sys
from collections import defaultdict

def solve(lineArr):
    if not lineArr:
        return -1
    mem = defaultdict(int)
    ret = -1
    for match in lineArr:
        mem[match] += 1
        if mem[match] >= 4:
            ret = max(ret, match)
    return ret * 4 if ret != -1 else -1

ret = []
for line in sys.stdin:
    lineArr = list(map(int, line.split()))
    ret.append(solve(lineArr))

with open('output2.txt', 'w') as file:
    file.writelines(' '.join(map(str, ret)))