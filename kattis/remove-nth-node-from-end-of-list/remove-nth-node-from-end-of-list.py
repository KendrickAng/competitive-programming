# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def length(self, head):
        ret = 0
        while head:
            ret += 1
            head = head.next
        return ret
    
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # get length of LL
        length = self.length(head)
        
        # head removal
        if length == n:
            return head.next
        
        # iterate LL and remove item we want to
        prev = head
        curr = head.next
        for _ in range(length - n - 1):
            prev = curr
            curr = curr.next
        prev.next = curr.next
        
        return head
    
"""
1 2 - 2
2

1 2 3 4 5  - 2
1 2 3 - 5

1 - 2
[]

1 2 - 1
1

2 - 1 = 1
# times to move prev ptr
then set prev.next = curr.next
"""