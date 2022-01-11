from collections import Counter

class Solution:
    def makeFDict(self, s):
        return Counter(s)
    
    def iterateStr(self, s, freqDict):
        for i in range(len(s)):
            c = s[i]
            if freqDict[c] == 1:
                return i
        return -1
    
    def firstUniqChar(self, s: str) -> int:
        # create frequency dict
        d = self.makeFDict(s)
        
        # iterate string, find first unique char
        ans = self.iterateStr(s, d)
        
        return ans