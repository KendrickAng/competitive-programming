class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        if not s: return ""
        stk = []
        seen = set()
        lastOccurrence = {c:i for i, c in enumerate(s)}
        
        for i, c in enumerate(s):
            if c not in seen:
                while stk and stk[-1] > c and lastOccurrence[stk[-1]] > i:
                    seen.discard(stk.pop())
                seen.add(c)
                stk.append(c)
        
        return "".join(stk)
        
    
"""
bcabc
abc

cbacdcbc c b
acdb

acbdadb
"""