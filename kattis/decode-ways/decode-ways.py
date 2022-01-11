class Solution:
    def numDecodings(self, s: str) -> int:
        # coutner
        digits = set(["1","2","3","4","5","6","7","8","9"])
        digits1 = set(["0","1","2","3","4","5","6","7","8","9"])
        digits2 = set(["0","1","2","3","4","5","6"])
        memo = [-1] * (len(s)+10)
        
        def dp(s, idx):
            nonlocal digits1, digits2, memo
            if idx > len(s) or idx == len(s)-1 and s[idx] == "0": return 0
            if idx >= len(s)-1: return 1
            ans = memo[idx]
            if ans != -1: return ans
            ans = 0
            if s[idx] in digits:
                ans += dp(s, idx+1)
            if s[idx] == "1" and idx+1 < len(s) and s[idx+1] in digits1:
                ans += dp(s, idx+2)
            if s[idx] == "2" and idx+1 < len(s) and s[idx+1] in digits2:
                ans += dp(s, idx+2)
            memo[idx] = ans
            return memo[idx]
        
        
        return dp(s, 0)
    
"""
12 - 2
1 2, 12

226| len(s)

2
22

2 2 6
2 26
22 6

0 - 0

06 - 0

form all accepted strings
for all candidate strings
    if s starts with a candidate string
        consume it and recurse
"""