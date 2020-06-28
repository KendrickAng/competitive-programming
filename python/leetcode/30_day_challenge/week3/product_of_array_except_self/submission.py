from Lib.typing import List
from collections import deque

def productExceptSelf(nums: List[int]) -> List[int]:
    # preprocessing
    prefix = []
    suffix = deque()

    productSoFar = 1
    for i in range(len(nums)):
        prefix.append(productSoFar)
        productSoFar *= nums[i]

    print(prefix)
    productSoFar = 1
    for i in range(len(nums)-1, -1, -1):
        suffix.appendleft(productSoFar)
        productSoFar *= nums[i]
    print(suffix)

    ret = []
    for i in range(len(nums)):
        ret.append(prefix[i] * suffix.popleft())

    return ret

print(productExceptSelf([1,2,3,4]))