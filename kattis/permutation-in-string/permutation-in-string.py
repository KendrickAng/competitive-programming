from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        hist1 = Counter(s1)
        hist2 = Counter()
        
        # init sliding windows
        left = 0
        right = len(s1)-1
        for i in range(left, right+1):
            hist2[s2[i]] += 1
        #print(hist1)
        
        # sliding window
        while True:
            #print(hist2)
            if hist1 == hist2:
                return True
            hist2[s2[left]] -= 1
            if hist2[s2[left]] == 0: del hist2[s2[left]]
                
            left += 1
            right += 1
            
            if right >= len(s2): break
            hist2[s2[right]] += 1
        
        return False