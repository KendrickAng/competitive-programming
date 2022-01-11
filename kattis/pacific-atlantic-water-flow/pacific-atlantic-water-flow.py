from collections import deque

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows = len(heights)
        cols = len(heights[0])
        
        def nxt(key):
            r, c = key
            currHeight = heights[r][c]
            directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
            ret = []
            for rOff, cOff in directions:
                newR = r + rOff
                newC = c + cOff
                if newR >= 0 and newR < rows and newC >= 0 and newC < cols and heights[newR][newC] >= currHeight:
                    ret.append((newR, newC))
            return ret
        
        def bfs(r, c, seen):
            dq = deque([(r, c)])
            while dq:
                key = dq.popleft()
                
                if key not in seen:
                    seen.add(key)
                    
                    for newKey in nxt(key): # iterate neighbors
                        dq.append(newKey)
        
        # bfs from pacific ocean
        pacific = set()
        for r in range(rows):
            bfs(r, 0, pacific)
        for c in range(cols):
            bfs(0, c, pacific)
            
        atlantic = set()
        for r in range(rows):
            bfs(r, cols-1, atlantic)
        for c in range(cols):
            bfs(rows-1, c, atlantic)
            
        # check similar
        ans = []
        for key in pacific:
            if key in atlantic:
                ans.append([key[0], key[1]])
                
        return ans
"""
2 1 
1 2

O(mn * (mn))

bfs from pacific, keep seen set
bfs from atlantic, keep seen set
iterate pacific set, see if atlantic set has same coord
    if yes, save as ans

retur nans
"""