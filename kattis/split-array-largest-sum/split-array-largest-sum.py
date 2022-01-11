class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        lo = max(nums)
        hi = sum(nums)
        
        # O(n * log(10^9))
        def splits(limit):
            cumsum = 0
            m_local = 0
            for num in nums:
                cumsum += num
                if cumsum > limit:
                    cumsum = num
                    m_local += 1
            if cumsum > 0: m_local += 1
            return max(m, m_local)
        
        lastAns = None
        while lo <= hi:
            mid = (lo + hi) // 2
            curr = splits(mid)
            #print(f"{mid}, {curr}")
            if curr == m:
                # go left
                lastAns = mid
                hi = mid - 1
            elif curr > m:
                # need too many splits, num is too small, go right
                lo = mid + 1
            else:
                # too little splits, num is too big, go left
                hi = mid - 1
                
        return lastAns
"""
base case:
m > (j-i+1) -> return float('inf')
m == (j-i+1) -> return max(arr)

dp(i,j, m) = sum(arr[0:b]) + dp(b, j, m-1)
"""