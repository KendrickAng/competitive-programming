class Solution:
    def countSubstrings(self, s: str) -> int:
        memo = {}
        def dp(l, r):
            if abs(l-r) == 1 or l == r: return s[l] == s[r]
            key = (l, r)
            if key not in memo:
                memo[key] = s[l] == s[r] and dp(l+1, r-1)
            return memo[key]
                
        ans = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                if dp(i, j):
                    ans += 1
                    
        return ans

"""
aaa
aa
 aa
 a

abc
a b c

aaa
a a a aa aa aaa

permutations? O(N!), too big
sliding windows? nope

a
aaa
bab

baab
bab

aaa

abaaba
xabx
"""