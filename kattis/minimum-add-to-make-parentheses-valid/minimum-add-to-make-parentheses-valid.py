"""
() 
((( - elemnts in stk = opening braces = add to final solution
))) - no elements in stk = discard and add one to count
()))(( - 4 
()(())(())
"""

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        # make stk
        stk = []
        moves = 0
        
        # iterates elements
        for c in s:
            
            if c == "(":
                stk.append(c)
            elif c == ")":
                if not stk:
                    moves += 1
                else:
                    stk.pop()
        
        return moves + len(stk)