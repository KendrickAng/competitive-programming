class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if sum(nums) < target:
            return 0
        
        left = 0
        right = 0
        windowSum = 0
        ans = float('inf')

        while right < len(nums):
            windowSum += nums[right]

            # maintain a window that doesnt meet requirements
            while windowSum >= target:
                ans = min(ans, right-left+1)
                windowSum -= nums[left]
                left += 1

            right += 1

        return ans
        
    
"""
smallest subarray that adds to target or greater

2 3 1 2 4 3, target = 7
4, 3

1 4 4
1

1 1 1 1 1 1 1 1
0 - no answer

left = 0
right = 0
windowSum = 0
ans = float('inf')

while right < len(nums):
    windowSum += nums[right]
    
    # maintain a window that doesnt meet requirements
    while left < right and windowSum >= target:
        ans = min(ans, right-left+1)
        windowSum -= nums[left]
        left += 1
    
    right += 1
    
return ans
"""