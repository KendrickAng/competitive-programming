import sys
import math
from collections import Counter

for line in sys.stdin:
    line = line[:-1]
    ctr = Counter(line)
    ans = math.factorial(len(line))
    for v in ctr.values():
        ans //= math.factorial(v)
    print(ans)