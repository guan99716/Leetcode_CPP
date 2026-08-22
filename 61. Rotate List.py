class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
from typing import Optional
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        nums = []
        curr = head
        while curr:
            nums.append(curr.val)
            curr = curr.next
        nums.reverse()
        nums[:k] = nums[:k].reverse()
        nums[k:] = nums[:k].reverse()
        
        # build list from nums
        dummy = ListNode(0)
        curr = dummy
        for n in nums:
            curr.next = ListNode(n)
            curr = curr.next
        return dummy.next