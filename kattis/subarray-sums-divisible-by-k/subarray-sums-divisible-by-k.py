from collections import defaultdict

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        # form prefix sums
        freqs = [0] * k
        freqs[0] = 1
        
        ans = 0
        runningSum = 0
        for num in nums:
            runningSum += num
            mod = runningSum % k
            
            # increment count
            ans += freqs[mod]
            
            # update frequencies
            freqs[mod] += 1
                
        return ans