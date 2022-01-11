class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # init pointer and zeroes
        zeroes = 0
        left = 0 # keeps track of next place to put number

        for right in range(len(nums)):
            if nums[right] != 0:
                nums[left] = nums[right]
                left += 1
            else:
                zeroes += 1
                
        # replace zeroes
        for i in range(len(nums)-1, len(nums)-zeroes-1, -1):
            nums[i] = 0
            
"""
0 1 0 3 12
1 1 0 3 12
1 3 0 3 12
1 3 12 3 12
1 3 12 0 0
"""