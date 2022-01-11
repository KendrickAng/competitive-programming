# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        currSum = 0
        hasSum = False
        
        def dfs(node):
            nonlocal currSum, hasSum, targetSum
            if not node: return
            
            currSum += node.val
            
            if currSum == targetSum and not node.left and not node.right: 
                hasSum = True
            if node.left:
                dfs(node.left)
            if node.right:
                dfs(node.right)
                
            currSum -= node.val
        
        dfs(root)
        
        return hasSum
        
    
"""
dfs and backtracking
"""