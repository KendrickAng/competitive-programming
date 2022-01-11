class Solution:
    def isValid(self, s: str) -> bool:
        def opening(c):
            return c in ("{", "[", "(")
        def match(l, r):
            if c == "}": return l == "{"
            if c == "]": return l == "["
            return l == "("
        
        stk = []
        
        for c in s:
            if opening(c):
                stk.append(c)
            elif not stk:
                return False
            elif match(stk[-1], c):
                stk.pop()
            else:
                return False
        
        return len(stk) == 0
    
"""
()
()[]{}
(]
([)]
{[]}
"""