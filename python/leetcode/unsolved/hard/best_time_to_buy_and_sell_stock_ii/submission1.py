from Lib.typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # returns a tuple ((i, j), mx) index of elements corrs to max.
        def findMax(prices):
            n = len(prices)
            ret = None
            mx = float('-inf')
            for i in range(n):
                for j in range(i+1, n):
                    profit = prices[j] - prices[i]
                    if profit > mx:
                        ret = (i,j)
                        mx = profit
            return ret, mx
        return findMax(prices)

sln = Solution()
print(sln.maxProfit([3,3,5,0,0,3,1,4])) # 6
print(sln.maxProfit([1,2,3,4,5])) # 4
print(sln.maxProfit([7,6,4,3,1])) # 0