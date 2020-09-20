from typing import List
from functools import cmp_to_key


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        def sort_function(a, b):
            return abs(a-x) - abs(b-x)

        arr.sort(key=cmp_to_key(sort_function))
        a = arr[:k]
        a.sort()

        return a


sln = Solution()
print(sln.findClosestElements([1,2,3,4,5],4,3))
print(sln.findClosestElements([1,2,3,4,5],4,-1))