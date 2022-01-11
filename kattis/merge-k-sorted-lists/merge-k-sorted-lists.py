# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        
        h = []
        for ll in lists:
            if not ll:
                continue
                
            # insert everything into the heap
            ptr = ll
            while ptr:
                heapq.heappush(h, ptr.val)
                ptr = ptr.next
        
        # extract from heap and create ll
        head = None
        last = None
        while h:
            val = heapq.heappop(h)
            if not head: # cfreate LL
                head = ListNode(val)
                last = head
            else:
                nxt = ListNode(val)
                last.next = nxt
                last = nxt
        
        return head
    
"""
min-heap nlogn

"""