class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        memo = {}

        def dp(idx, toRob):
            if idx == n:
                return 0
            
            key = (idx, toRob)
            if key not in memo:
                if toRob:
                    memo[key] = nums[idx] + dp(idx+1, False)
                else:
                    # not robbing here, can rob next place or not
                    memo[key] = max(dp(idx+1, False), dp(idx+1, True))
                
            return memo[key]

        ans = max(dp(0, True), dp(0, False))    
        #print(memo)
        return ans
"""
1 2 3 1
4

2 7 9 3 1

n = len(nums)
memo = [None] * n

def dp(idx, toRob):
    pass
    
return max(dp(0, True), dp(0, False))
"""