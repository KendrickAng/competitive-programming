"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    def canInsert(self, prev, curr, insertVal):
        # prev smaller, curr larger
        return prev.val <= insertVal and insertVal <= curr.val
    
    def insertAfter(self, node, insertVal):
        n = Node(insertVal, node.next)
        node.next = n
    
    def insert(self, head: 'Node', insertVal: int) -> 'Node':
        # handle empty case
        if head is None:
            n = Node(insertVal)
            n.next = n
            return n

        # insert as per normal, 1 -> new (2) -> 3
        curr = head
        nxt = head.next
        while True:
            if self.canInsert(curr, nxt, insertVal):
                self.insertAfter(curr, insertVal)
                return head
            curr = nxt
            nxt = nxt.next
            if curr == head:
                break
                
        # insert after largest element
        prev = head
        curr = head.next
        largestE = head.val
        largestNode = head
        while True:
            if curr.val >= largestE:
                largestE = curr.val
                largestNode = curr
            prev = curr
            curr = curr.next
            if prev == head:
                break

        self.insertAfter(largestNode, insertVal)
        return head
            

"""
  v
1 3 4 
-----

insert 5

1 3 4 <-
-----
insert 2

1 2 3 4 <-
-------

1 2 3 4 <- 
-------

insert 5
keep track of orgiinal node
if hit the node again
    insert at head

otherwise
two pointrs - prev curr

3 3 3  insert 5
---- insert anywhere

-1 2 3 inesrt 2 inesrt 5 0
-----


"""