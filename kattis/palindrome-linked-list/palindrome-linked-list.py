# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def flatten(self, node):
        ret = []
        while node:
            ret.append(node.val)
            node = node.next
        return ret
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        arr = self.flatten(head)
            
        return arr == arr[::-1]