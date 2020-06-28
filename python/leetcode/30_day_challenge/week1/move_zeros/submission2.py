from Lib.typing import List

# O(N) time, O(1) space
def moveZeros(nums: List[int]) -> None:
    if not nums:
        return

    A = 0 # invariant: points to the leftmost 0
    B = 0 # invariant: points to the first nonzero AFTER A

    while A < len(nums) and B < len(nums):
        if nums[A] != 0:
            A += 1
        elif nums[A] == 0 and (B <= A or nums[B] == 0):
            B += 1
        else:
            temp = nums[A]
            nums[A] = nums[B]
            nums[B] = temp

nums = [0,1,0,3,12]
moveZeros(nums)
print(nums)