class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = -1
        ansS = ""
        
        def expand(i, j):
            if i < 0 or j >= len(s) or s[i] != s[j]: 
                return -1, ""
            length = 1 if i == j else 2
            i -= 1
            j += 1
            while i >= 0 and j < len(s):
                if s[i] == s[j]:
                    length += 2
                else:
                    break
                i -= 1
                j += 1
            return length, s[i+1:j]
        
        for i in range(len(s)):
            ans1, s1 = expand(i, i)
            if ans1 > ans:
                ans = ans1
                ansS = s1
            ans2, s2 = expand(i, i+1)
            if ans2 > ans:
                ans = ans2
                ansS = s2
        
        return ansS