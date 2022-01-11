"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        first = None
        last = None
        # build tree with inorder traversal
        def helper(node):
            nonlocal first, last
            if not node: return
            # inorder traversal
            helper(node.left)
            
            # save the leftmost node once
            if not first:
                first = node 
            
            # connect current node to the last
            if last:
                node.left = last
                last.right = node
            # update current last node
            last = node
            
            helper(node.right)
        
        helper(root)
        first.left = last
        last.right = first
        return first
        