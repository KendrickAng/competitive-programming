class NumMatrix:

    def dp2(self, row, col):
        if row < 0 or col < 0: return 0
        if row == 0 and col == 0: return self.matrix[row][col]
        key = (0,0,row,col)
        ans = self.memo.get(key)
        if ans is not None: return ans
        self.memo[key] = self.dp2(row,col-1) + self.dp2(row-1,col) - self.dp2(row-1,col-1) + self.matrix[row][col]
        return self.memo[key]
                
    def dp(self, r1, c1, r2, c2):
        if r1 == 0 and c1 == 0 and (r1,c1,r2,c2) not in self.memo:
            self.memo[(r1,c1,r2,c2)] = self.dp2(r2,c2)
        key = (r1,c1,r2,c2)
        ans = self.memo.get(key)
        if ans is not None: return ans
        self.memo[key] = self.dp(0, 0, r2, c2) - self.dp(0, 0, r2, c1-1) - self.dp(0, 0, r1-1, c2) + self.dp(0, 0, r1-1, c1-1)
        return self.memo[key]
    
    def __init__(self, matrix: List[List[int]]):
        # generate the dict
        self.memo = {}
        self.matrix = matrix

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.dp(row1, col1, row2, col2)


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)