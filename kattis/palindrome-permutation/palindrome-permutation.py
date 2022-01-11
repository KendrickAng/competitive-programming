from collections import Counter

class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        # form the frequency dict
        freq = Counter(s)
        
        # check the dict
        oddCount = 1
        for c, times in freq.items():
            if times % 2 != 0:
                oddCount -= 1
            if oddCount < 0:
                return False
        
        return True