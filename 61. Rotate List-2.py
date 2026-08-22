class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
from typing import Optional
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # find end and count num of nodes
        if not head:
            return None
        curr = head
        n = 1
        while curr.next:
            n += 1
            curr = curr.next
        end = curr
        end.next = head
        
        # find where to truncate
        curr = end
        for i in range(n-k):
            curr = curr.next
        newHead = curr.next
        curr.next = None
        
        return newHead
        
        
        
            
            