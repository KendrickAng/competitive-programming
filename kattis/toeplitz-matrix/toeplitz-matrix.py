class Solution:
    def allSameDiagonal(self, r, c, matrix):
        item = matrix[r][c]
        def isValid():
            return r >= 0 and r < len(matrix) and c >= 0 and c < len(matrix[0])
        
        while isValid():
            if matrix[r][c] != item:
                return False
            r += 1
            c += 1
            
        return True
            
            
    
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        # loop all columns
        rows = len(matrix)
        cols = len(matrix[0])
        for col in range(cols):
            if not self.allSameDiagonal(0, col, matrix):
                return False
        
        # loop all rows
        for row in range(rows):
            if not self.allSameDiagonal(row, 0, matrix):
                return False
            
        return True