
w = int(input())
n = int(input())
area = 0
for _ in range(n):
    ww, l = list(map(int, input().split()))
    area += ww * l
print(area // w)