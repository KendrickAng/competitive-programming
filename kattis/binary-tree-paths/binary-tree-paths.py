# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        paths = []
        
        def dfs(node, sofar):
            nonlocal paths
            if not node.left and not node.right: # leaf node
                return paths.append("->".join([str(x) for x in sofar]))
            if node.left:
                sofar.append(node.left.val)
                dfs(node.left, sofar)
                sofar.pop()
            if node.right:
                sofar.append(node.right.val)
                dfs(node.right, sofar)
                sofar.pop()
        
        dfs(root, [root.val])
        return paths