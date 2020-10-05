class Solution:
    def queryString(self, S: str, N: int) -> bool:
        for n in range(1, N+1):
            if bin(n)[2:] not in S:
                return False
        return True

sln = Solution()
print(sln.queryString("0110", 3))
print(sln.queryString("0110", 4))