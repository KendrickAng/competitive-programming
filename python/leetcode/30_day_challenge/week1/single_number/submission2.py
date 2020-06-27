from typing import List

# O(N) time, O(1) space. BIT MANIPULATION!
def singleNumber(nums: List[int]) -> int:
    ret = 0
    for num in nums:
        ret ^= num
    return ret

print(singleNumber([4,1,2,1,2]))

