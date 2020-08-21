from Lib.typing import List


class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        if len(A) <= 1:
            return A
        return list(filter(lambda e: e % 2 == 0, A)) + list(filter(lambda e: e % 2 != 0, A))