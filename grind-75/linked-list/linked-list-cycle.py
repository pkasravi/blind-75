# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def hasCycle(self, head: Optional[ListNode]) -> bool:
    if not head:
        return False

    slow, fast = head, head
    result = False
    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            result = True
            break
    return result
