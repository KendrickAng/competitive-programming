r, s = list(map(int, input().split()))
matrix = []
for _ in range(r):
    matrix.append([x for x in input()])

def around(r, c):
    x_off = [-1,0,1,1,1,0,-1,-1]
    y_off = [-1,-1,-1,0,1,1,1,0]
    ret = []
    for i in range(len(x_off)):
        ret.append((r+x_off[i], c+y_off[i]))
    return ret

def valid(matrix, r, c):
    return r >= 0 and r < len(matrix) and c >= 0 and c < len(matrix[0])

def count(matrix, r, c):
    if valid(matrix, r, c) and matrix[r][c] != ".":
        return 0
    ret = 0
    for x, y in around(r, c):
        if valid(matrix, x, y) and matrix[x][y] == "o":
            ret += 1
    return ret

def handshakes(matrix, r, c):
    if valid(matrix, r, c) and matrix[r][c] == ".":
        return 0
    ret = 0
    for rr, cc in around(r, c):
        if valid(matrix, rr, cc) and matrix[rr][cc] == "o":
            ret += 1
    return ret


max_neighbours = 0
ans = 0
for ri in range(r):
    for ci in range(s):
        max_neighbours = max(max_neighbours, count(matrix, ri, ci))
        ans += handshakes(matrix, ri, ci)

ans //= 2
ans += max_neighbours
print(ans)