import math

n, k = map(int, input().split())
if k >= 335 or k >= math.log2(n):
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")