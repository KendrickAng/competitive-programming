# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        # init vars
        offset = float('inf')
        val = None
        def dfs(node):
            nonlocal offset, val
            if not node: return
            if abs(node.val - target) < offset:
                offset = abs(node.val - target)
                val = node.val
            dfs(node.left)
            dfs(node.right)
        
        dfs(root)
        return val