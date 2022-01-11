from collections import defaultdict

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        def twoPointer(target, i, lo, hi):
            nonlocal slns, nums
            while lo < hi:
                # find a two sum matching target
                numAtLow = nums[lo]
                numAtHigh = nums[hi]
                summ = numAtLow + numAtHigh
                if summ == target:
                    slns.append([nums[i], numAtLow, numAtHigh])
                    # find next non-dup
                    while lo < hi and lo < len(nums) and nums[lo] == numAtLow:
                        lo += 1
                    while lo < hi and hi >= 0 and nums[hi] == numAtHigh:
                        hi -= 1
                elif summ < target:
                    lo += 1
                elif summ > target:
                    hi -= 1
        
        nums.sort()
        n = len(nums)
        
        # iterate all first elements
        slns = []
        for i in range(n):
            # skip dups
            if i > 0 and nums[i] == nums[i-1]:
                continue
            twoPointer(0-nums[i], i, i+1, n-1)
        
        return slns
    
"""
-1 0 1 2 -1 -4
-1 -1 2
-1 0 1

-4 -1 -1 0 1 2

gives 0

store e -> set of idxs?

sln = []
go through all eles, fill hashmap
sort digits

for all i:
    for all j:
        find 0 - nums[i] - nums[j]
        pick all idxs not i or j
        add sln
        
return sln
"""