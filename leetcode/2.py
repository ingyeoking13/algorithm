from tkinter.messagebox import NO
from typing import Optional 
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode()
        append = 0
        while l1 is not None or l2 is not None:
            val = append

            if l1 is not None:
                val += l1.val
            if l2 is not None:
                val += l2.val

            result.val = val % 10
            append = val // 10

            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
        
        if append: 
            n = ListNode()
            n.val = append
            n.next = None
            result.next =  n

        return result

        