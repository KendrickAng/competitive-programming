class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        memo = [None] * n
        
        def dp(idx): # is i creasing subseq
            nonlocal memo
            if idx == 0: return 1 # just the elemnt itself
            if memo[idx] is None:
                ans = 1 # at least nums[i] itself
                for j in range(idx):
                    if nums[j] < nums[idx]:
                        ans = max(ans, dp(j)+1)
                memo[idx] = ans
            return memo[idx]

        ans = float('-inf')
        for i in range(n):
            ans = max(ans, dp(i))
            
        return ans
"""
1 5 2 3
"""