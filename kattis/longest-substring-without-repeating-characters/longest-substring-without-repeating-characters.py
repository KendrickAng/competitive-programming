class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def hasRepeat():
            nonlocal hist
            for count in hist:
                if count > 1: return True
            return False
        
        hist = [0] * 128
        l = 0
        r = 0
        ans = 0
        
        while r < len(s):
            c = s[r]
            hist[ord(c)] += 1
            
            while hasRepeat():
                cc = s[l]
                hist[ord(cc)] -= 1
                l += 1
            
            ans = max(ans, r-l+1)
            r += 1
        
        return ans
    
"""
abcabcbb
abc

bbbb
b

pwwkew
      
wke

init histogram
sliding window
left = right = 0
while right < len(s):
    add charcter at rgiht to window
    while window has repeat chars
        histogram - char at left
        left += 1
    ans = max(ans, j-i+1)
return ans

P(N)
"""