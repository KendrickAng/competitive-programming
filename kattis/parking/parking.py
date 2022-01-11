a,b,c = list(map(int, input().split()))
arr = [0 for _ in range(0, 101)]
a1, a2 = list(map(int, input().split()))
b1, b2 = list(map(int, input().split()))
c1, c2 = list(map(int, input().split()))
for i in range(a1, a2):
    arr[i] += 1
for i in range(b1, b2):
    arr[i] += 1
for i in range(c1, c2):
    arr[i] += 1
ans = 0
for d in arr:
    if d == 1:
        ans += a
    elif d == 2:
        ans += b * 2
    elif d == 3:
        ans += c * 3
print(ans)