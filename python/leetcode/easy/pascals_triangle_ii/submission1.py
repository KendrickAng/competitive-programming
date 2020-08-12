from Lib.typing import List
from math import comb

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # the ith row jth col has value (i choose j), where i, j both start from 0
        ret = []
        for i in range(0, rowIndex + 1):
            ret.append(comb(rowIndex, i))
        return ret

sln = Solution()
print(sln.getRow(3))