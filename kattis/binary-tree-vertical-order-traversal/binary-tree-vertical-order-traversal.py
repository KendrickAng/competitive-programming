# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict, deque

class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        columnTable = defaultdict(list)
        q = deque([(root, 0)])
        
        while q:
            node, col = q.popleft()
            columnTable[col].append(node.val)
            
            if node.left:
                q.append((node.left, col-1))
            if node.right:
                q.append((node.right, col+1))
        
        colOrder = sorted(columnTable.keys())
        return [columnTable[k] for k in colOrder]

        
        