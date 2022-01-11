"""
[1,2,3,4] k =3
[2,3,4,1]

2 3 4 1

1 2 3 4 5 6 7 k =3
5 6 7 4 1 2 3
5 6 7 1 2 3 4

1 2 3 4 7 6 5


1 4 3 2

"""

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(nums, fr, to):
            n = (to - fr + 1) // 2
            for i in range(n):
                tmp = nums[i+fr]
                nums[i+fr] = nums[to-i]
                nums[to-i] = tmp
                
        n = len(nums)
        k %= n
        reverse(nums, n-k, n-1)
        reverse(nums, 0, n-k-1)
        reverse(nums, 0, n-1)
        
