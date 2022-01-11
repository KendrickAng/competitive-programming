class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0
        nums.sort()
        bot3 = nums[:4]
        top3 = nums[-4:]
        
        return min(b-a for a,b in zip(bot3, top3))
    
"""
1 2 3 4
1 1 1 1

1 2 3 4 5
1 2 1 1 1

5 3 2 4
2 2 2 2
0

1 5 0 10 14
1 1 0 1   1
1

6 6 0 1 1 4 6
6 6 4 4 4 4 6
2

0 1 1 4 6 6 6

1   5  6 14 15
14 14 14 14 15
1

20 75 81 82 95
81 81 81 82 81
"""