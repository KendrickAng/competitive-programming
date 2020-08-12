class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    # use a dummy head so we can ensure the ret pointer always points to the current node
    dummyHead = ListNode()
    ret = dummyHead
    carry = False
    # add both numbers with increasing factor
    while l1 is not None and l2 is not None:
        total = l1.val + l2.val
        # expend the carry
        if carry:
            carry = False
            total += 1
        # calculate the sum of numbers
        if total >= 10:
            carry = True
            total -= 10
        ret.next = ListNode(total)
        ret = ret.next

        l1 = l1.next
        l2 = l2.next

    # either both lists are exhausted, or just one
    if l1 is None and l2 is None:
        if carry:
            carry = False
            ret.next = ListNode(1)
    elif l1 is None:
        if carry:
            # update l2 to reflect the carry
            carry = False
            l2 = addTwoNumbers(ListNode(1), l2)
        ret.next = l2
    elif l2 is None:
        if carry:
            # update l1 to reflect the carry
            carry = False
            l1 = addTwoNumbers(ListNode(1), l1)
        ret.next = l1

    return dummyHead.next

def printList(x: ListNode):
    ret = ""
    while x is not None:
        ret = str(x.val) + ret
        x = x.next
    print(ret)

one = ListNode(2, ListNode(4, ListNode(3)))
two = ListNode(5, ListNode(6, ListNode(4)))
a = addTwoNumbers(one, two)
printList(a)