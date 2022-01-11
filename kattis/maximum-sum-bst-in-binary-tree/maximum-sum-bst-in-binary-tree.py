# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def dfs(node):
            nonlocal ans
            if not node:
                return float('-inf'), float('inf'), 0

            lmax, lmin, lsum = dfs(node.left)
            rmax, rmin, rsum = dfs(node.right)
                        
            # check if curr tree is also valid bst
            if lmax < node.val and node.val < rmin:
                # valid bst
                newMax = max(lmax, rmax, node.val)
                newMin = min(lmin, rmin, node.val)
                newSum = lsum + rsum + node.val
                ans = max(ans, newSum)
                return newMax, newMin, newSum
            else:
                # not valid bst, return the empty subtree
                return float('inf'), float('-inf'), 0

        dfs(root)
        return ans    
"""
max so far, min so far, sum so far
when returning from recurse, if current tree is bst, save the answer as solution


ans = 0

def dfs(node):
    if not node.left and not node.right:
        return node.val, node.val, node.val
    
    lmax, lmin, lsum = dfs(node.left)
    rmax, rmin, rsum = dfs(node.right)
    
    ans = max(ans, lsum, rsum)
    
    # check if curr tree is also valid bst
    if lmax < node.val and node.val < rmin:
        # valid bst
        newMax = max(lmax, rmax, node.val)
        newMin = min(lmin, rmin, node.val)
        newSum = lsum + rsum + node.val
        return newMax, newMin, newSum
    else:
        # not valid bst, return the empty subtree
        return float('-inf'), float('inf'), 0
    
dfs(root)
return ans
    
"""