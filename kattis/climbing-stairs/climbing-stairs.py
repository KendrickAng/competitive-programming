class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [None] * (n + 10)
        
        def dp(n):
            if n == 1: return 1
            if n == 2: return 2
            if memo[n] is None:
                memo[n] = dp(n-1) + dp(n-2)
            return memo[n]
        
        return dp(n)