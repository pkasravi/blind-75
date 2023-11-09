/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
 * 
 * Solution Description:
 * The idea here is to write a LinkedList class with an append method. Then with
 * two pointers we iterate through the two input linked lists, taking the node
 * with the lesser value and appending it to the new linked list. Finally we
 * return the head of the new linked list.
 *
 * Steps:
 * 1 - Create an empty LinkedList
 * 2 - Traverse the two input lists using a while loop continuing until one
 * becomes null
 * 3 - Compare the two nodes and append the one with a smaller value to the new
 * linked list. The append method should take care of severing the connection to
 * the old linked list
 * 4 - Have two more while loops that iterate until both lists are empty/null
 * 5 - Return the head of the newly created linked list
 *
 * Complexity Analysis:
 * Time: O(n) because we must iterate through both linked lists to solve the
 * problem
 * Space: O(1) because we aren't allocating memory for anything new simply
 * reordering the pointers. We create a dummy node but that is always the same
 * regardless of input size.
 *
 * -----------------------------------------------------------------------------
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
 public:
  LinkedList() : head{nullptr}, tail_{nullptr} {}
  ListNode* head;
  void Append(ListNode* node) {
    if (head == nullptr) {
      head = node;
      tail_ = node;
      return;
    }
    tail_->next = node;
    tail_ = node;
    tail_->next = nullptr;
  }
 private:
  ListNode* tail_;
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == nullptr || list2 == nullptr) {
    return list1 == nullptr ? list2 : list1;
  }

  LinkedList merged{};
	const auto move_node = [&](ListNode* node) {
    const auto tmp{node->next};
    merged.Append(node);
    return tmp;
  };
  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val < list2->val) {
      list1 = move_node(list1);
    } else {
      list2 = move_node(list2);
    }
  }
  while (list1 != nullptr) {
    list1 = move_node(list1);
  }
  while (list2 != nullptr) {
    list2 = move_node(list2);
  }
  return merged.head;
}
