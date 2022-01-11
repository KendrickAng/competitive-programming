class Solution:
    def removeDuplicates(self, s: str) -> str:
        stk = []
        for c in s:
            if len(stk) == 0: 
                stk.append(c)
            elif stk[len(stk)-1] == c:
                stk.pop()
            else:
                stk.append(c)
        return "".join(stk)
        
# abbaca -> ca 
# azxxzy -> ay