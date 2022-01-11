class Solution:
    def isValid(self, grid, row, col):
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]): 
            return False
        return True
    
    # returns size of island starting at current point
    def dfs(self, grid, row, col, index):
        iSize = 0
        rows = len(grid)
        cols = len(grid[0])
        
        def flood(grid, row, col, index):
            nonlocal iSize

            # count the island and flood
            grid[row][col] = index
            iSize += 1
            
            for x, y in [(-1,0), (0,1), (1,0), (0,-1)]: # N, E, S, W
                newRow = row + y
                newCol = col + x
                if self.isValid(grid, newRow, newCol) and grid[newRow][newCol] == 1:
                    flood(grid, row+y, col+x, index)
                    
        flood(grid, row, col, index)
        return iSize
    
    def largestIsland(self, grid: List[List[int]]) -> int:
        # loop each point
        rows = len(grid)
        cols = len(grid[0])
        ans = float('-inf')

        # generate idxs
        index = 2
        islands = defaultdict(int)
        islands[0] = 0 # island with index 0 size 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    islands[index] = self.dfs(grid, r, c, index)
                    index += 1
        
        #print(grid)
        
        # calculate islands
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    north = grid[r-1][c] if self.isValid(grid, r-1, c) else -1
                    east = grid[r][c+1] if self.isValid(grid, r, c+1) else -1
                    south = grid[r+1][c] if self.isValid(grid, r+1, c) else -1
                    west = grid[r][c-1] if self.isValid(grid, r, c-1) else -1
                    #print(north, east, south, west)
                    # filter invalid 
                    tmp = set([i for i in [north,east,south,west] if i != -1])
                    islandSize = sum([islands[idx] for idx in tmp]) + 1
                    ans = max(ans, islandSize)
                    
        return ans if ans != float('-inf') else rows * cols
"""
1 1 1
0 0 0
0 0 0

1 0
0 1

1 0 ->
0 1 ->

1 0
1 1

1 1
1 0

1 1
1 1

1 1
1 1

1 0 1
0 1 0
1 0 1

1 1 1
0 1 0
1 0 1
 4
 
iterate every pt in grid
    if 0 -> change to 1, find size of island
    bakctrack
O(n^4)

ON^2
for each pt in grid
    if islandSize[r][c] not filled:
        dfs() # flood fill
ON^2    
for each pt islandSize:
    if pt.size == 0:
        try combining all 4 islands to N E S W
                
"""