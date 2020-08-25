from typing import List
from copy import deepcopy

# Define a solution to be [c0,c1..,cn], where c0 is the column index of the queen
# in row 1 in the solution.
class Solution:
    answer = None
    n = None
    def solveNQueens(self, n: int) -> List[List[str]]:
        Solution.answer = []
        board = [[False for _ in range(n)] for _ in range(n)]
        Solution.n = n
        self.helper(0, board)
        return list(map(self.postProcess, Solution.answer))

    # we assume that n is correctly input.
    # the game board, for simplicity, is a 2d array.
    def helper(self, row:int, ret: List[List[int]]):
        # there is an answer if we manage to generate slns for all rows
        if row >= Solution.n:
            return True
        # try to insert something for row i
        for col in range(Solution.n):
            # pre-visit
            retCopy = deepcopy(ret)
            retCopy[row][col] = True
            if self.isValid(retCopy, row, col) and self.helper(row+1, retCopy):
                Solution.answer.append(retCopy)
            else:
                # post-visit
                retCopy[row][col] = False
        return False

    # Checks if no queen placements are violated
    # Note that we only need to check the top, since we insert by increasing row.
    def isValid(self, bd: List[List[int]], row: int, col: int):
        n = Solution.n
        # Check the column
        for i in range(row):
            if bd[i][col]:
                return False
        # Check upper diagonal, on left side
        for i, j in zip(range(row-1,-1,-1), range(col-1,-1,-1)):
            if bd[i][j]:
                return False
        # Check upper diagonal, on right side
        for i, j in zip(range(row-1,-1,-1), range(col+1, n)):
            if bd[i][j]:
                return False
        return True

    def postProcess(self, board):
        def helper(row):
            ret = ""
            for i in range(len(row)):
                ret += "Q" if row[i] else "."
            return ret
        return list(map(helper, board))

sln = Solution()
print(sln.solveNQueens(1))

