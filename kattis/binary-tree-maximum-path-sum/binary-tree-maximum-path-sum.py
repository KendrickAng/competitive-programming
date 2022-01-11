# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        maxSum = float('-inf')
        
        def helper(node):
            nonlocal maxSum
            if not node: return 0
            left = max(helper(node.left), 0) # can choose not to take path if < 0
            right = max(helper(node.right), 0)
        
            # update maxsum if needed
            maxSum = max(maxSum, left + node.val + right)
            
            # otherwise return a straight line path starting from either lft or right
            return max(node.val + left, node.val + right)
            
        helper(root)
        return maxSum
    
"""
path doesnt need to start from root or a leaf
make all possbile paths
for each node either end at current node or continue this path
need O(N)

bfs with dp?
dfs with dp?

memo of node -> max path
"""