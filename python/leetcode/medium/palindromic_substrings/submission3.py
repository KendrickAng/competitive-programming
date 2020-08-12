# Using dp too
# O(N^2) time
class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[0 for i in range(n)] for j in range(n)]

        ret = 0
        for i in reversed(range(n)):
            for j in range(i, n):
                dp[i][j] = s[i] == s[j] and ((j-i) < 3 or dp[i+1][j-1])
                ret += dp[i][j]
        return ret

sl = Solution()
print(sl.countSubstrings("aaa")) # 6
print(sl.countSubstrings("abc")) # 3
print(sl.countSubstrings("aba")) # 4