from math import ceil

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def canEat(bananas):
            hours = 0
            for pile in piles:
                hours += ceil(pile / bananas)
                if hours > h:
                    return False
            return True
        
        lo = 1
        hi = max(piles)
        minAns = None
        while lo <= hi:
            mid = (lo + hi) // 2
            if canEat(mid):
                # go left
                minAns = mid
                hi = mid - 1
            else:
                # go right
                lo = mid + 1
        return minAns
    
"""
30 11 23 4 20, h = 5
30

30 11 23 4 20, h = 6
23
- 2nd largest element

3 6 7 11, h = 5
7

3 6 7 11, h = 6
6

3 6 7 11, h = 7
6

3 6 7 11, h = 8
4

"""