r, c, zr, zc = list(map(int, input().split()))
original = []
for _ in range(r):
    original.append([x for x in input()])

ans = []
for row in range(r):
    tmp = []
    for col in range(c):
        char = original[row][col]
        for _ in range(zc):
            tmp.append(char)
    for _ in range(zr):
        ans.append(tmp.copy())

for anss in ans:
    print("".join(anss))
