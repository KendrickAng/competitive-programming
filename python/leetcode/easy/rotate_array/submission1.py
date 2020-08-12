from Lib.typing import List

# O(N) time, O(N) space
def rotate(nums: List[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    n = len(nums)
    ret = [None for i in range(n)]
    for i in range(n):
        offset = (i + k) % n
        ret[offset] = nums[i]
    for i in range(n):
        nums[i] = ret[i]

arr = [1,2,3,4,5,6,7]
rotate(arr, 3)
print(arr)
