# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        ans = []
        delete = set(to_delete)
        
        def dfs(node):
            nonlocal ans
            if not node: return
            dfs(node.left)
            dfs(node.right)
            if node.left and node.left.val == -1:
                node.left = None
            if node.right and node.right.val == -1:
                node.right = None
            if node.val in delete:
                if node.left: ans.append(node.left)
                if node.right: ans.append(node.right)
                node.val = -1
        
        dfs(root)
        if root.val != -1: ans.append(root)
        return ans