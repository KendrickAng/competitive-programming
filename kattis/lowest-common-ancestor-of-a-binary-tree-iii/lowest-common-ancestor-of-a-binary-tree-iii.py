"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""
"""
 3 
 
 3
    1
    
    3
5       1
"""
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        # create set of parents of p
        parents = set()
        while p is not None:
            parents.add(p.val)
            p = p.parent
        
        # iterate q and output first node that contains p's parent
        while q is not None:
            if q.val in parents:
                return q
            q = q.parent
        
        return None