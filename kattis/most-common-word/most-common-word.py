import re
from collections import Counter

class Solution:
    def splitString(self, s):
        return re.split("[ !?',;.]", s)
    
    def createFreqDict(self, tokens):
        return Counter(tokens)
    
    def outputMostFreqUnbannedWord(self, tokens, frequencyDict, banned):
        banned = set(banned)
        mostFreqWord = None
        mostFreqCount = -1
        for k, v in frequencyDict.items():
            if k not in banned and v > mostFreqCount:
                mostFreqWord = k
                mostFreqCount = v
        return mostFreqWord
        
    
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # split string in parts
        tokens = self.splitString(paragraph)
        tokens = [s.lower() for s in tokens if s]
        
        # create frequency dict
        frequencyDict = self.createFreqDict(tokens)
        
        # iterate dict and output most frequent unbanned word
        ans = self.outputMostFreqUnbannedWord(tokens, frequencyDict, banned)
        
        return ans
