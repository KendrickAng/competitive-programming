# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:
"""
for each row, binary search cols
O(rows * log(col))
"""
class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        rows, cols = binaryMatrix.dimensions()
        
        def binarySearch(row):
            nonlocal cols, binaryMatrix
            lo = 0
            hi = cols - 1
            leftMostIdx = float('inf')
            while lo <= hi:
                mid = (lo + hi) // 2
                curr = binaryMatrix.get(row, mid)
                print(curr)
                # get the leftmost 1
                if curr == 1:
                    # go left
                    leftMostIdx = mid
                    hi = mid - 1
                else:
                    # go right
                    lo = mid + 1
                    
            return leftMostIdx
            
        col = float('inf')
        for row in range(rows):
            col = min(col, binarySearch(row))
            
        return col if col != float('inf') else -1
            
            