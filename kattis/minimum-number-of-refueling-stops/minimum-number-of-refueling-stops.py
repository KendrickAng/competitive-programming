class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        memo = {}
        
        # dp[k][i] = max distance reached by performing k refuelling trips among first i stations
        def dp(k, i):
            if i == -1: return startFuel
            if k == 0: return startFuel
            key = (k, i)
            
            if key not in memo:
                memo[key] = max(dp(k-1, i-1) + (stations[i][1] if dp(k-1, i-1) >= stations[i][0] else 0),\
                                dp(k, i-1))
            
            return memo[key]
        
        for k in range(len(stations) + 1):
            if dp(k, len(stations)-1) >= target:
                return k
        return -1