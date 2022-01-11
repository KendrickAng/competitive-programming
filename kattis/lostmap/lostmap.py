from queue import Queue
from collections import defaultdict

n = int(input())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

# adj list
adjlist = defaultdict(list)
for i in range(n):
    for j in range(i+1, n):
        if matrix[i][j] != 0:
            adjlist[i].append(j)

# bfs
q = Queue()
q.put((0, -1))
explored = set()
explored.add(0)
pairs = []
while not q.empty():
    node, parent = q.get()
    for child in adjlist[node]:
        if child not in explored:
            q.put((child, node))
            pairs.append((node, child))
            explored.add(child)

for pair in pairs:
    print(f"{pair[0]+1} {pair[1]+1}")



