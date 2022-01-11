class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows = len(image)
        cols = len(image[0])
        seen = set()
        
        def inImage(r, c):
            return r >= 0 and r < rows and c >= 0 and c < cols
        
        def dfs(r, c, currColor):
            if not inImage(r, c): return
            if (r,c) in seen: return
            if image[r][c] != currColor: return
            image[r][c] = newColor
            seen.add((r,c))
            directions = ((0,1),(0,-1),(1,0),(-1,0))
            for y, x in directions:
                newR = r + y
                newC = c + x
                dfs(newR, newC, currColor)
        
        dfs(sr, sc, image[sr][sc])
        return image
    
    