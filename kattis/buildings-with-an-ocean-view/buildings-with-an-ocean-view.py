"""
maintain a stack of buildings in decreasing order
4
4 2
4 3 
4 3 1
"""

class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        heights = [(h, i) for i, h in enumerate(heights)]
        stk = []
        
        for height, idx in heights:
            if not stk:
                stk.append((height, idx))
            else:
                # maintain stack invariant
                # building in decreasing order - while stk top shorter, pop
                while stk and stk[-1][0] <= height:
                    stk.pop()
                    
                stk.append((height, idx))
        
        return [i for _, i in stk]