class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        d = {}
        d[0] = 0
        total = 0
        ans = 0

        for i, num in enumerate(nums):
            total += num
            want = total - k

            if want in d:
                # get length of current subarray
                ans = max(ans , (i+1)-d[want])

            if total not in d:
                d[total] = i+1

        return ans    
"""
-2 -1 2 1, k = 1


# dict that stores subarray sum to length of subarray, want earliest point
d = {}
d[0] = 0
total = 0
ans = 0

for i, num in enumerate(nums):
    total += num
    want = k - total

    if want in d:
        # get length of current subarray
        ans = max(ans , (i+1)-d[want])

    d[total] = i+1
    
return ans
"""