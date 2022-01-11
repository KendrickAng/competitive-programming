t = int(input())
EPSILON = 10 ** -7
for _ in range(t):
    x1, x2 = list(map(int, input().split()))
    if x1 > x2:
        tmp = x1
        x1 = x2
        x2 = tmp
    
    # solve
    lo = 0
    hi = x1 / 2
    while hi - lo > EPSILON:
        mid1 = (hi-lo) * 1/3 + lo
        mid2 = (hi-lo) * 2/3 + lo
        ans1 = (x1-2*mid1) * (x2-2*mid1) * mid1
        ans2 = (x1-2*mid2) * (x2-2*mid2) * mid2
        if -ans1 < -ans2:
            hi = mid2
        else:
            lo = mid1
    print((x1-2*lo) * (x2-2*lo) * lo)
    