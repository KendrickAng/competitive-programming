class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        # calculate prefix sums
        n = len(cardPoints)
        prefix = [0]
        for i in range(n):
            tmp = prefix[-1] + cardPoints[i]
            prefix.append(tmp)
        #print(prefix)
        
        # move fixed sliding window
        left = k
        right = n
        ans = -1
        while left >= 0:
            leftSum = prefix[left]
            rightSum = prefix[n] - prefix[right]
            points = leftSum + rightSum
            #print(f"{leftSum} {rightSum} {points}")
            ans = max(ans, points)
            left -= 1
            right -= 1
        
        return ans
    
"""
1 2 3 4 5 6 1, k = 3
1 6 5

9 7 7 9 7 7 9, k = 7
take all

idea: fixed sliding window, length k
1. calculate prefix sums
2. move fixed window (size n - k) from rightmost to leftmost
"""