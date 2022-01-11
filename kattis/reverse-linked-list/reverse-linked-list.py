# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:            
        lst = []
        
        def dfs(node):
            nonlocal lst
            if not node: return
            lst.append(node.val)
            dfs(node.next)

        dfs(head)
        
        ptr = head
        while ptr:
            ptr.val = lst.pop()
            ptr = ptr.next
        
        return head