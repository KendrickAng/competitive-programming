class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = [-1] * (amount+1)
        coins.sort(reverse=True)
        
        def dp(amount):
            nonlocal memo
            if amount < 0: return float('inf')            
            if amount == 0: return 0
            #print(amount)
            if memo[amount] == -1:
                #print(amount)
                ans = float('inf')
                for coin in coins:
                    ans = min(ans, dp(amount-coin)+1)
                memo[amount] = ans
            return memo[amount]
        
        ans = dp(amount)
        return ans if ans != float('inf') else -1
    
"""
1 2 5, 11

2, 3
-1

1, 0
0

1, 1
1

dp  - amount left
O(amount * coins.length)

negative - return float(inf) - not possible
zero - return 0 - no coins needed

P(amount) = min of (trying all coins and the rmaining amount left)

dp(amount):
    if amount < 0 : return -1
    if amount == 0 : return 0
    if memo[amunt] == -1:
        
        
    return memo[amount]
    
"""