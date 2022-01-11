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

def lazyPrims(s = 0):
    pq = []
    visited = [False for _ in range(n)]
    def addEdges(nodeIndex):
        visited[nodeIndex] = True
        for to, cost in adjlist[nodeIndex]:
            if not visited[to]:
                heapq.heappush(pq, (cost, nodeIndex, to))

    m = n - 1
    edgeCount, mstCost = 0, 0
    mstEdges = [None for _ in range(m)]
    addEdges(s)

    while pq and edgeCount != m:
        edge = heapq.heappop(pq)
        nodeIndex = edge[2] # cost, from, to

        if visited[nodeIndex]:
            continue

        mstEdges[edgeCount] = edge
        edgeCount += 1
        mstCost += edge[0]

        addEdges(nodeIndex)

    return (mstCost, mstEdges)
    
cost, ans = lazyPrims()
# print(cost)
for cost, frm, to in ans:
    print(f"{frm+1} {to+1}")