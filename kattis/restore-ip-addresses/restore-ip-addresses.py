class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # variables
        ans = []
        
        def allValid(sofar):
            for num in sofar:
                num = int(num)
                if num < 0 or num > 255:
                    return False
            return True
        
        def dfs(i, depth, sofar):
            if i > len(s) or depth > 4: 
                return
            if depth == 4 and i == len(s) and allValid(sofar):
                ans.append(".".join(sofar))
                return
            
            # consume 1 if possible
            if i+1 <= len(s):
                sofar.append(s[i:i+1])
                dfs(i+1, depth+1, sofar)
                sofar.pop()
            
            # consume 2, no leading zeros
            if i+2 <= len(s) and s[i] != "0":
                sofar.append(s[i:i+2])
                dfs(i+2, depth+1, sofar)
                sofar.pop()
                
            # consume 3, no leading zeros
            if i+3 <= len(s) and s[i] != "0":
                sofar.append(s[i:i+3])
                dfs(i+3, depth+1, sofar)
                sofar.pop()
        
        dfs(0, 0, [])
        return ans
    
"""
25525511135
         

255 255 111 35
255 255 11 135

0000
0 0 0 0

1111
1 1 1 1

010010
0 10 0 10
0 100 1 0

101023
1 0 10 23
1 0 102 3
10 1 0 23
10 10 2 3
101 0 2 3

3 ^ length of ip address (12) = 10^6

dfs with pointer
dfs()
if at depth 4:
    return
try to consume 1
try to consume 2 if noleading ero
try to consume 3 if no leading ero

"""