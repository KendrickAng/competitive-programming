# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        total = 0
        
        def dfs(node, sofar):
            nonlocal total
            sofar.append(node.val)
            
            if not node.left and not node.right:
                total += int("".join([str(x) for x in sofar]))
                
            if node.left:
                dfs(node.left, sofar)
            if node.right:
                dfs(node.right, sofar)
                
            sofar.pop()
        
        dfs(root, [])
        return total