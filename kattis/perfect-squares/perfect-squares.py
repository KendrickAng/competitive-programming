class Solution:
    def numSquares(self, n: int) -> int:
        memo = [None] * (n+1)

        def dp(num):
            if num == 1: return 1
            if num == 0: return 0
            if num < 1: return float('inf')
            
            if memo[num] is None:
                ans = float('inf')
                limit = floor(sqrt(num))
                for i in range(limit+1, 0, -1):
                    ans = min(ans, 1 + dp(num - i*i))

                memo[num] = ans

            return memo[num]


        ret = dp(n)    
        #print(memo)
        return ret
"""
n

memo = [float('inf')] * (n+1)

def dp(num):
    if n == 1:
        return 1
    if n < 1:
        return float('inf')
    
    if num not in memo:
        ans = 0
        
        limit = floor(sqrt(n))
        for i in range(limit+1):
            ans = min(ans, 1 + dp(num - i*i))
            
        memo[num] = ans
    
    return memo[num]
        
    
return dp(n)
"""