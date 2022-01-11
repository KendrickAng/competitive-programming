class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        n = len(nums)
        memo = {}
        
        def dp(idx, firstRobbed):
            if idx == n-1 and firstRobbed:
                return 0 # can't rob this house
            if idx >= n:
                return 0
            
            key = (idx, firstRobbed)
            if key not in memo:
                if idx == 0 and firstRobbed:
                    memo[key] = nums[idx] + dp(idx+2, firstRobbed)
                elif idx == 0 and not firstRobbed:
                    memo[key] = dp(idx+1, firstRobbed)
                else:
                    memo[key] = max(nums[idx] + dp(idx+2, firstRobbed), dp(idx+1, firstRobbed))
            
            return memo[key]
        
        ans = max(dp(0, True), dp(0, False))
        return ans
    
"""
2 3 2

"""