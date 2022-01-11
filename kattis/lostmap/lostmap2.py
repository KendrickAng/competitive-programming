import heapq
from collections import defaultdict

n = int(input())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

# adj list
adjlist = defaultdict(list)
for i in range(n):
    for j in range(n):
        if i != j and matrix[i][j] != 0:
            adjlist[i].append((j, matrix[i][j]))

# Prim's algorithm for MST
h = []
visited = set()
ans = []

# init
visited.add(0)
for to, cost in adjlist[0]:
    heapq.heappush(h, (cost, 0, to))

while h and len(ans) != n-1:
    cost, frm, to = heapq.heappop(h)
    if to in visited:
        continue
    else:
        ans.append((frm, to))
        visited.add(to)
        for newto, cost in adjlist[to]:
            if newto not in visited:
                heapq.heappush(h, (cost, to, newto))

for frm, to in ans:
    print(f"{frm+1} {to+1}")

# tmp = 0
# for frm, to in ans:
#     tmp += matrix[frm][to]
# print(tmp)

# tmp2 = 0
# ans2 = [(1,4),(1,5),(2,4),(3,5),(4,6),(4,7)]
# for frm, to in ans2:
#     tmp2 += matrix[frm-1][to-1]
# print(tmp2)