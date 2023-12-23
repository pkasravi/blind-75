/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/reverse-linked-list/
 * 
 * Solution Description:
 * We will traverse the linked list and as we go we will move the pointers such
 * that we end up reversing the order of the linked list.
 *
 * Steps:
 * 1 - We will use two pointers current and previous. Initialize current to head
 *     and previous to nullptr
 * 2 - While current is not null we store current's next to a temporary pointer
 * a - Set current's next to previous
 * b - Set previous to current
 * c - Set current to temporary
 * 3 - Finally return previous as the head of our new linked list since it will
 *     finish the loop at the tail of the original linked list
 *
 * Complexity Analysis:
 * Time: O(n) since we iterate through the linked list once linearly
 * Space: O(1) because we create 3 pointers regardless of input size.
 *
 * -----------------------------------------------------------------------------
 */

ListNode* reverseList(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode* current{head};
	ListNode* previous{nullptr};
	ListNode* temp{nullptr};

	while (current != nullptr) {
		temp = current->next;
		current->next = previous;
		previous = current;
		current = temp;
	}
	return previous;
}

