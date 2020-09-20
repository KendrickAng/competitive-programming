from typing import List


class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        squaresToWalk = self.countSquaresOfDigit(grid, 0) + 1 # include start
        start = self.findDigit(grid, 1)
        END = self.findDigit(grid, 2)
        EXPLORED = [[False for _ in range(cols)] for _ in range(rows)]
        EXPLORED[start[0]][start[1]] = True
        RET = [0]
        self.dfs(grid, start, squaresToWalk, EXPLORED, END, RET)
        return RET[0]

    def dfs(self, grid, curr, squaresToWalk, EXPLORED, END, RET):
        if curr == END and squaresToWalk == 0:
                return True
        # top, right, bottom, left
        for move in [(-1,0), (0,1), (1,0), (0,-1)]:
            nextx = curr[0]+move[0]
            nexty = curr[1]+move[1]
            next = (nextx, nexty)
            if self.isValid(next, grid) and not EXPLORED[nextx][nexty]:
                EXPLORED[nextx][nexty] = True
                if self.dfs(grid, next, squaresToWalk-1, EXPLORED, END, RET):
                    RET[0] += 1
                EXPLORED[nextx][nexty] = False
        return False

    def isValid(self, next, grid):
        rows = len(grid)
        cols = len(grid[0])
        nextRow, nextCol = next
        if nextRow < 0 or nextRow >= rows or nextCol < 0 or nextCol >= cols:
            return False
        return grid[nextRow][nextCol] != -1

    def findDigit(self, grid, digit):
        rows = len(grid)
        cols = len(grid[0])
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == digit:
                    return row, col
        return None

    def countSquaresOfDigit(self, grid, digit):
        rows = len(grid)
        cols = len(grid[0])
        ret = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == digit:
                    ret += 1
        return ret

sln = Solution()
grid = [[0,1],[2,0]]
print(sln.uniquePathsIII(grid)) # 2