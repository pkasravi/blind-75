# ------------------------------------------------------------------------------
# See merge-two-sorted-lists.cc for notes
# ------------------------------------------------------------------------------
from typing import Optional

class ListNode:
    def __init__(self, val: int = 0, next_node: ListNode = None):
        self.val = val
        self.next = next_node

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, node: ListNode) -> None:
        if not self.head:
            self.head = node
            self.tail = node
            return
        self.tail.next = node
        self.tail = node
        self.tail.next = None

def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    if not list1 or not list2:
        return list2 if not list1 else list1

    merged = LinkedList()
    def move_node(node: ListNode) -> ListNode:
        tmp = node.next
        merged.append(node)
        return tmp

    while list1 and list2:
        if list1.val < list2.val:
            list1 = move_node(list1)
        else:
            list2 = move_node(list2)
    while list1:
        list1 = move_node(list1)
    while list2:
        list2 = move_node(list2)
    return merged.head
