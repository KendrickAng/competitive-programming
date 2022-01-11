# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        # iterate dfs inorder traversal
        stk = []
        last = None
        curr = root
        while stk or curr:
            if curr: # go left
                
                # preorder
                #print(curr.val)
                
                stk.append(curr)
                curr = curr.left
            else: # pop and go right
                curr = stk.pop()
                
                # inorder
                if last and last.val >= curr.val:
                    return False
                last = curr
                    
                curr = curr.right
            
        return True
"""
        5
    1       4
        3       6
"""