class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:        
        temp = defaultdict(list)
        for word in words:
            it = iter(word)
            temp[next(it)].append(it)
            
        ans = 0
        for c in s:
            arr = temp[c]
            temp[c] = []
            for word in arr:
                nxt = next(word, None)
                if nxt:
                    temp[nxt].append(word)
                else:
                    ans += 1
        
        return ans
"""
isSubsequence(word, s) = word[0] == s[0] and isSubsequence(word[1:], s[1:])
    OR word[0] != s[0] and isSubsequence(word[1:], s)

base case: word is empty
"""