class UFDS:
    def __init__(self, n):
        self.parents = list(range(n))
        self.ranks = [0] * n
        self.sizes = [1] * n
        self.numdisjoint = n

    def find(self, x):
        xp = x
        children = []
        while xp != self.parents[xp]:
            children.append(xp)
            xp = self.parents[xp]
        for c in children:
            self.parents[c] = xp
        return xp

    def union(self, a, b):
        ap = self.find(a)
        bp = self.find(b)
        if ap == bp:
            return

        if self.ranks[ap] < self.ranks[bp]:
            self.parents[ap] = bp
            self.sizes[bp] += self.sizes[ap]
        elif self.ranks[bp] < self.ranks[ap]:
            self.parents[bp] = ap
            self.sizes[ap] += self.sizes[bp]
        else:
            self.parents[bp] = ap
            self.ranks[ap] += 1
            self.sizes[ap] += self.sizes[bp]

        self.numdisjoint -= 1

    def size(self, x):
        return self.sizes[self.find(x)]

class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        ones = set()
        ufds = UFDS(len(positions))
        
        ufds_id = 0
        keyToUid = {}
        for r, c in positions:
            keyToUid[(r,c)] = ufds_id
            ufds_id += 1
        
        # tiles to NSEW within bounds and w/ value of 1
        def around(r, c):
            ret = []
            directions = ((0,1),(0,-1),(1,0),(-1,0))
            for rr, cc in directions:
                newR, newC = r + rr, c + cc
                if newR >= 0 and newR < m and newC >= 0 and newC < n and (newR, newC) in ones:
                    ret.append((newR, newC))
            return ret
        
        islands = 0
        ans = []
        for r, c in positions:
            # skip islands we have seen before
            if (r,c) in ones:
                ans.append(islands)
                continue
                
            ones.add((r, c)) # keep track of 1s for aroudn()
            
            ard = around(r, c)
            #print(ard)
            
            # combine islands
            for rr, cc in ard:
                key1 = ufds.find(keyToUid[(r,c)])
                key2 = ufds.find(keyToUid[(rr,cc)])
                if key1 != key2:
                    ufds.union(key1, key2)
                    islands -= 1
            islands += 1

            # add number of islands
            ans.append(islands)
                
        return ans
    
"""
put tile next to island -> # islands same or decreases based on number of islands connected
put tile next to place with no island -> # islands ++
iterate through each position
get all valid 1s
union all together
output number of disjoint sets
"""