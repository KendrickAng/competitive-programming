class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        def is_overlap(a, b):
            return a[0] < b[1] and b[0] < a[1]
        
        intervals.sort()
        n = len(intervals)
        arr = [intervals[0]]
        ans = 0
        
        for i in range(1, n):
            a = arr[-1]
            b = intervals[i]
            if is_overlap(a, b):
                if b[1] > a[1]:
                    # remove b (just skip it)
                    ans += 1
                else:
                    # remove a
                    arr[-1] = b
                    ans += 1
            else:
                # no removal, put in b
                arr.append(b)
        
        return ans
"""
1 2, 2 3, 3 4, 1 3

sort intervals by first then second field
n = len(intervals)
memo = {}

def dp(idx):
    if idx >= n-1:
        return 0 # one interval, no need to remove
    
    if idx not in memo:
        a = intervals[idx]
        b = intervals[idx+1]
        if is_overlap(a, b):
            # remove one with greater endpoint
            
    return memo[idx]
        
return dp(0)
"""