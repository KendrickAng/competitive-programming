from Lib.typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        citations.sort()
        for i in range(n):
            h = citations[i]
            noMore = i      # num of papers with no more than h citations
            atLeast = n - i # num of papers with at least h citations
            # if I'm a citation, update ans
            if h >= atLeast:
                return atLeast
        return 0 # vacously true

sln = Solution()
print(sln.hIndex([3,0,6,1,5]))
print(sln.hIndex([0]))
print(sln.hIndex([100]))