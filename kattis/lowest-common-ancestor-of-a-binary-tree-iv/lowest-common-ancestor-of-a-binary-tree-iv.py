# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        want = set(nodes)
        
        def postorder(node):
            if not node:
                return None
            if node in want:
                return node
            
            l = postorder(node.left)
            r = postorder(node.right)
            if l and r:
                return node
            return l or r
        
        return postorder(root)