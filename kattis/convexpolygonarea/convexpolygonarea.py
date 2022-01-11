n = int(input())

def polygonArea(pts):
    area = 0
    j = len(pts) - 1
    for i in range(0, len(pts)):
        area += (pts[j][0]+pts[i][0]) * (pts[j][1]-pts[i][1])
        j = i # store previous vertex to i
    return -area / 2

for _ in range(n):
    tokens = list(map(int, input().split()))
    m = int(tokens[0])
    points = []
    idx = 1
    for i in range(m):
        points.append((tokens[idx], tokens[idx+1]))
        idx += 2
    print(polygonArea(points))