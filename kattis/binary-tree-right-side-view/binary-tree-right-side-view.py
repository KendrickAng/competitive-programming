# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:        
    
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        d = {}
        maxHeight = -1
        
        def revPreorder(root, h):
            nonlocal d, maxHeight
            if root is None: return
            if h not in d:
                d[h] = root.val
            maxHeight = max(maxHeight, h)
            revPreorder(root.right, h+1)
            revPreorder(root.left, h+1)

        revPreorder(root, 0)
        return [d[i] for i in range(maxHeight+1)]