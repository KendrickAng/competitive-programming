class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1: 
            return 0
        
        left = 0
        right = 0
        product = 1
        ans = 0
        while right < len(nums):
            product *= nums[right]

            while product >= k:
                product /= nums[left]
                left += 1

            ans += right - left + 1
            right += 1

        return ans
            
    
"""
10 5 2 6, k = 100
10
5
2
6
10, 5
5, 2
2, 6
5, 2, 6

x / y < 100
y < x / 100

left = 0
right = 0
while right < len(nums):
    product *= numsright]
    
    while product > k:
        product /= nums[left]
        left += 1
        ans += 1
    
    ans += ap(right-left+1)
    right += 1

return ans
"""