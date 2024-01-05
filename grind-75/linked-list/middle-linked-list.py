# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def middleNode(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head:
        return None

    slow, fast = head, head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow
