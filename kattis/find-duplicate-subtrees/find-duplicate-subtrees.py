# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        nodeToKey = {}
        
        # inorder and store
        def inorder(node):
            nonlocal nodeToKey
            if not node: return ""
            left = inorder(node.left)
            right = inorder(node.right)
            key = left + str(node.val) + right
            nodeToKey[node] = key
            return key
            
        inorder(root)
        
        # postorder and store
        def postorder(node):
            nonlocal nodeToKey
            if not node: return "x"
            left = postorder(node.left)
            right = postorder(node.right)
            key = left + right + str(node.val)
            nodeToKey[node] += key
            return key
        
        postorder(root)
        #print(nodeToKey)
        ans = []
        dq = deque([root])
        seen = {}
        while dq:
            node = dq.popleft()
            key = nodeToKey[node]
            if key in seen:
                if seen[key] == 1:
                    ans.append(node)
                seen[key] += 1
            else:
                seen[key] = 1
            
            # add neighbours
            if node.left:
                dq.append(node.left)
            if node.right:
                dq.append(node.right)
                
        return ans
"""
need hash - preoder + inorder
for a node, we know its key
then go thorugh each node, keep track of hashes seen
    if seen a hash, store that node
return answers
"""