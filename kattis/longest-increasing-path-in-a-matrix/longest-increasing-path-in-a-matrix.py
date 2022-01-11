class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        mem = {}
        rows = len(matrix)
        cols = len(matrix[0])
        maxPath = -1

        def jump(r, c):
            ret = []
            directions = ((0,1),(0,-1),(1,0),(-1,0))
            currVal = matrix[r][c]
            for rOff, cOff in directions:
                newR = r + rOff
                newC = c + cOff
                if newR >= 0 and newR < rows and newC >=0 and newC < cols\
                    and currVal < matrix[newR][newC]:
                    ret.append((newR, newC))
            return ret
        
        def dp(r, c):
            key = (r, c)

            if key not in mem:
                ans = 1

                # jump gives all candidates NSEW greater than current element and within bounds
                for rr, cc in jump(r, c):
                    ans = max(ans, 1 + dp(rr, cc))
                mem[key] = ans

            return mem[key]

        for r in range(rows):
            for c in range(cols):
                maxPath = max(maxPath, dp(r, c))

        return maxPath    
"""
mem = {}
rows = len(matrix)
cols = len(matrix[0])
maxPath = -1

def dp(r, c):
    
    key = (r, c)
    
    if key not in mem:
        ans = 1
        
        # jump gives all candidates NSEW greater than current element and within bounds
        for rr, cc in jump(r, c):
            ans = max(ans, 1 + dp(rr, cc))
        mem[key] = ans
    
    return mem[key]

for r in range(rows):
    for c in range(cols):
        maxPath = max(maxPath, dp(r, c))

return maxPath
"""