from typing import List

# O(N) time, O(N) space.
def singleNumber(nums: List[int]) -> int:
    store = set()
    for num in nums:
        if num in store:
            store.remove(num)
        else:
            store.add(num)
    return store.pop()

print(singleNumber([4,1,2,1,2]))
