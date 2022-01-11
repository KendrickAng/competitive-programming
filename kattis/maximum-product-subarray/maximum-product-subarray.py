class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxSoFar = nums[0]
        minSoFar = nums[0]
        ans = maxSoFar
        
        for i in range(1, len(nums)):
            curr = nums[i]
            tmp = max(curr, maxSoFar * curr, minSoFar * curr)
            minSoFar = min(curr, maxSoFar * curr, minSoFar * curr)
            maxSoFar = tmp
            ans = max(ans, maxSoFar)
            
        return ans