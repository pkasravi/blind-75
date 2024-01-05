/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/
 * 
 * Solution Description:
 * We will use fast and slow pointers to solve this problem. The main idea is
 * that since the fast pointer is moving at twice the rate of the slow pointer
 * when the fast pointer reaches the end of the linked list, the slow pointer
 * will be pointing at the middle node.
 *
 * Steps:
 * 1 - Create fast and slow pointers initialized to head
 * 2 - Loop while fast is not null and fast's next is not null
 * a - In the case of an odd number of nodes fast will have reached the end and
 *     will not have a next node to move on to, satisfying the second breaking
 *     condition
 * b - In the case of an even number of nodes, we must iterate so that slow ends
 *     up pointing to the second middle node, to do this we allow the fast
 *     pointer to go beyond the linked list and become null. Thus, satisfying
 *     the first breaking condition
 * 3 - Return the slow pointer
 *
 * Complexity Analysis:
 * Time: O(n) because we only iterate through the list once
 * Space: O(1) because we only ever create two pointers, regardless of the
 * 				input's size
 *
 * -----------------------------------------------------------------------------
 */

ListNode* middleNode(ListNode* head) {
	if (head == nullptr) {
    return nullptr;
  }
	ListNode* slow{head};
	ListNode* fast{head};

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

