# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class CBTInserter:

    def __init__(self, root: Optional[TreeNode]):
        def init(root):
            arr = [None]
            q = deque([root])
            while q:
                node = q.popleft()
                arr.append(node)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            return arr, len(arr)
        
        self.arr, self.next = init(root)
        self.root = root

    def insert(self, val: int) -> int:
        parent = self.arr[self.next // 2]
        node = TreeNode(val)
        
        if self.next % 2 == 0:
            # left child
            parent.left = node
        else:
            # right child
            parent.right = node
            
        self.arr.append(node)
        self.next += 1
        return parent.val
            
    def get_root(self) -> Optional[TreeNode]:
        return self.root


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()