from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        def valid(r, c):
            return r >= 0 and r < len(grid) and c >= 0 and c < len(grid[0]) and grid[r][c] == 1
        def nxt(r, c):
            directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
            ans = []
            for rOff, cOff in directions:
                if valid(r + rOff, c + cOff):
                    ans.append((r + rOff, c + cOff))
            return ans
            
        rows = len(grid)
        cols = len(grid[0])
        q = deque()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    q.append((r, c, 0))

        # bfs 
        ans = 0
        seen = set()
        while q:
            # process one batch of oranges
            n = len(q)
            for _ in range(n):
                r, c, time = q.popleft()
                ans = max(ans, time)

                for rr, cc in nxt(r, c): # next tiles with oranges thats not rotten
                    grid[rr][cc] = 2
                    q.append((rr, cc, time + 1))

        # check if all rotted
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    return -1

        return ans
    
"""
2 2
1 1
0 0
2 0

2 1 1
1 1 0
0 1 1

2 1 1
0 1 1
1 0 1

0 2

seen = set() # dont come back to same point
q = deque()
for r in range(rows)
    for c in range(cols)
        if grid[r][c] == 2:
            q.append((r, c, 0))
         
# bfs 
ans = 0
while q:
    # process one batch of oranges
    n = len(q)
    for _ in range(n):
        r, c, time = q.popleft()
        grid[r][c] = 2 # rotten
        seen.add((r,c))
        ans = max(ans, time)
        
        for rr, cc in nxt(r, c): # next tiles with oranges thats not rotten
            if (rr,cc) in seen:
                 continue
            q.append((rr, cc, time + 1))

# check if all rotted
for r in range(rows)
    for c in range(cols)
        if grid[r][c] == 1:
            return -1
            
return ans
    
"""