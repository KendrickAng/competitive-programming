from typing import List

# incorrect solution since empty subarrays are not considered valid.
def maxSubArray(nums: List[int]) -> int:
    if not nums:
        return 0

    best_sum = float('-inf')
    # invariant: contains max of subarrays ending in j
    current_sum = 0

    for num in nums:
        # 0 to consider the empty subarray (for -ve numbers)
        current_sum = max(0, current_sum + num)
        best_sum = max(best_sum, current_sum)

    return best_sum

print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
