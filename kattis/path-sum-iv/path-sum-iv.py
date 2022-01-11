class Solution:
    def pathSum(self, nums: List[int]) -> int:
        # regenerate the tree
        tree = {}
        for num in nums:
            s = str(num)
            a, b, c = int(s[0]), int(s[1]), int(s[2])
            tree[(a,b)] = c
        
        # dfs on the tree
        total = 0
        
        def isLeaf(key):
            nonlocal tree
            return left(key) not in tree and right(key) not in tree
        
        def left(key):
            return key[0]+1, key[1]*2-1
        
        def right(key):
            return key[0]+1, key[1]*2
        
        def dfs(key, sofar):
            #print(key)
            nonlocal tree, total
            sofar += tree[key]
            if isLeaf(key):
                total += sofar
            if left(key) in tree:
                dfs(left(key), sofar)
            if right(key) in tree:
                dfs(right(key), sofar)
                
        dfs((1,1), 0)
        return total

"""
            1
        7       1
    5
5
"""