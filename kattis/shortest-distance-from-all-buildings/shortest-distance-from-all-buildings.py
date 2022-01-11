class Solution:
    def shortestDistance(self, grid):
        if not grid or not grid[0]: return -1
        M, N, buildings = len(grid), len(grid[0]), sum(val for line in grid for val in line if val == 1)
        hit, distSum = [[0] * N for i in range(M)], [[0] * N for i in range(M)]

        def BFS(start_x, start_y):
            visited = [[False] * N for k in range(M)]
            visited[start_x][start_y], count1, queue = True, 1, collections.deque([(start_x, start_y, 0)])
            while queue:
                x, y, dist = queue.popleft()
                for i, j in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                    if 0 <= i < M and 0 <= j < N and not visited[i][j]:
                        visited[i][j] = True
                        if not grid[i][j]:
                            queue.append((i, j, dist + 1))
                            hit[i][j] += 1
                            distSum[i][j] += dist + 1
                        elif grid[i][j] == 1:
                            count1 += 1
            return count1 == buildings  

        for x in range(M):
            for y in range(N):
                if grid[x][y] == 1:
                    if not BFS(x, y): return -1
        return min([distSum[i][j] for i in range(M) for j in range(N) if not grid[i][j] and hit[i][j] == buildings] or [-1])

# class Solution:
#     def shortestDistance(self, grid: List[List[int]]) -> int:
#         rows = len(grid)
#         cols = len(grid[0])

#         # count # buildings
#         buildings = 0
#         for r in range(rows):
#             for c in range(cols):
#                 if grid[r][c] == 1:
#                     buildings += 1
#         print(buildings)
                    
#         def manhattan(r1, c1, r2, c2):
#             return abs(r1-r2) + abs(c1-c2)
        
#         def nxt(r, c):
#             directions = ((0,1),(0,-1),(1,0),(-1,0))
#             ret = []
#             for rOff, cOff in directions:
#                 newR = r + rOff
#                 newC = c + cOff
#                 if newR >= 0 and newR < rows and newC >= 0 and newC < cols and\
#                     (grid[newR][newC] == 0 or grid[newR][newC] == 1):
#                     ret.append((newR, newC))
#             return ret
                    
#         def bfs(r, c):
#             seen = set()
#             dq = deque([((r, c), 0)])
#             dist = 0
#             buildingsHit = 0

#             while dq:
#                 key, trav = dq.popleft()

#                 if key not in seen:
#                     seen.add(key)

#                     if grid[key[0]][key[1]] == 1: # hit a building, can't conitnue
#                         dist += trav
#                         buildingsHit += 1
#                         continue

#                     for newR, newC in nxt(key[0], key[1]):
#                         dq.append(((newR, newC), trav+1))
            
#             return dist if buildingsHit == buildings else float('inf')

#         # bfs from each node
#         ans = float('inf')
#         for r in range(rows):
#             for c in range(cols):
#                 if grid[r][c] == 0:
#                     ans = min(ans, bfs(r, c))

#         return ans if ans != float('inf') else -1
    
"""
1 0 2 0 1
0 0 X 0 0
0 0 1 0 0
total distaince: 7


1 X
ans: 1

1
ans: -1 cannot build anywhere

can bfs from all points

idea:
first count number of building sto reach
try to bfs from all empty spots
during bfs, if we reached a buildint calc the manhattan dist to it
at end of a bfs, if all houses reached count it as a sln

rows = len(grid)
cols = len(grid[0])

# count # buildings
buildings = 0
for r in range(rows):
    for c in range(cols):
        if grid[r][c] == 1:
            buildings += 1

def bfs(r, c):
    seen = set()
    dq = deque((r, c))
    dist = 0
    buildingsHit = 0
    
    while dq:
        key = dq.popleft()
            
        if key not in seen:
            seen.add(key)
            
            if grid[key[0], key[1]] == 1: # hit a building, can't conitnue
                dist += manhattan(r, c, key[0], key[1])
                buildingsHit += 1
                continue
            
            for newR, newC in nxt(key[0], key[1]):
                dq.append((newR, newC))
    
    

# bfs from each node
ans = -1
for r in range(rows):
    for c in range(cols):
        if grid[r][c] == 0:
            ans = max(ans, bfs(r, c))
            
return ans

"""