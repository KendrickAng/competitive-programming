# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        tmp = []
        
        def dfs(node):
            if not node.left and not node.right:
                tmp.append(node.val)
                return None
            
            if node.left:
                node.left = dfs(node.left)
            if node.right:
                node.right = dfs(node.right)
            
            return node
        
        while root:
            tmp.clear()
            root = dfs(root)
            ans.append(list(tmp))
            
        return ans