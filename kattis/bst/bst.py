n = int(input())
vals = []
for _ in range(n):
     vals.append(int(input()))

class Node:
    def __init__(self, val, left=None, right=None):
        self.left = left
        self.right = right
        self.val = val

class BST:
    def __init__(self):
        self.root = None
        self.ctr = 0

    def insert(self, val):
        prev = None
        ptr = self.root
        depth = 0
        while ptr is not None:
            depth += 1
            prev = ptr
            if ptr.val < val:
                ptr = ptr.right
            else:
                ptr = ptr.left
        if prev == None:
            self.root = Node(val)
        elif prev.val < val:
            prev.right = Node(val)
        else:
            prev.left = Node(val)
        self.ctr += depth
        print(self.ctr)

bst = BST()
for val in vals:
    bst.insert(val)