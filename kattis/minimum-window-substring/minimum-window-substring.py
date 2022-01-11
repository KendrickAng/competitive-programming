from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def isSln(hist):
            nonlocal impt
            for k, v in impt.items():
                if hist[ord(k)] < v:
                    return False
            return True
            
        if len(t) > len(s):
            return "" # no solnt

        hist = [0] * 128
        impt = Counter(t)
        l = 0
        r = 0
        minL = -1
        minR = -1
        minLen = float('inf')
        
        while r < len(s):
            c = s[r] # get char
            hist[ord(c)] += 1 # add to hsi
            
            # if valid sln,try to shirnk it
            if isSln(hist):
                while (s[l] not in impt or (s[l] in impt and hist[ord(s[l])] > impt[s[l]])):
                    cc = s[l]
                    hist[ord(cc)] -= 1
                    l += 1

                # save after deduction
                if r - l + 1 < minLen:
                    minL = l
                    minR = r
                    minLen = r - l + 1
                
                #print(l)
                
            r += 1
        
        return s[minL:minR+1] if minL != -1 and minR != -1 else ""
    
"""
ADOBECODEBANC
           
ABC
BANC - has all letters of ABC inside (can also have N)

a
a

a
aa
"" - no solution

hist = [0] * 128
impt = set(t)
l = r = 0
minL = 0
minR = 0
minLen
while r < len(s):
    c = s[r]
    hist[c] += 1
    while isvalidsln(hist) and l < len(s) and s[l] in impt and hist[l] > 1:
        cc = s[l]
        hist[cc] -= 1
        l += 1
    
        save solution
        if r - l + 1 < minLen:
            minL = l
            minR = r
            minLen = r - 1 + 1

    r += 1
O(m + n)
"""