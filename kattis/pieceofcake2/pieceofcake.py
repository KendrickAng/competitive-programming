n, h, v = list(map(int, input().split()))

hh = max(h, n-h)
vv = max(v, n-v)

print(hh * vv * 4)