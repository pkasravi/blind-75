# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def reverseList(head: Optional[ListNode]) -> Optional[ListNode]:
    if head == None or head.next == None:
        return head

    current, previous, temp = head, None, None

    while current:
        temp = current.next
        current.next = previous
        previous = current
        current = temp
    return previous
