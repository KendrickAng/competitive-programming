# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
"""
inorder
generate bst recursively

"""

class Solution:
    def flatten(self, node):
        inorder = []
        def helper(node):
            nonlocal inorder
            if not node:
                return
            helper(node.left)
            inorder.append(node.val)
            helper(node.right)
        
        helper(node)
        return inorder
    
    def makeBST(self, arr):
        if not arr:
            return None
        
        # get middle eleemn
        mid = len(arr) // 2;
        root = TreeNode(arr[mid])
        
        # split the array and recursive on each half
        left = arr[:mid]
        root.left = self.makeBST(left)
        
        right = arr[mid+1:]
        root.right = self.makeBST(right)
        
        return root
    
    def balanceBST(self, root: TreeNode) -> TreeNode:
        # flatten bst
        inorder = self.flatten(root)
        #print(inorder)
        
        # generate bst recursively
        return self.makeBST(inorder)
        