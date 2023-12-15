/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/linked-list-cycle/description/
 * 
 * Solution Description:
 * We will use slow and fast pointers to traverse the list. The slow pointer
 * will move ahead one node on every iteration and the fast pointer will move
 * ahead two nodes. If there is a cycle the pointers will eventually meet.
 *
 * Steps:
 * 1 - Create slow and fast pointers
 * 2 - Use a while loop to traverse linked list with the two pointers
 * 3 - If the fast pointer or its next becomes null we can break the
 * 		 loop because there is no cycle
 * 4 - If the two pointers become equal we have found the cycle and can quit
 *
 * Complexity Analysis:
 * Time: O(n) because in the worst case we traverse the linked list twice and 2n
 *       reduces to O(n)
 * Space: O(1) because we only create two pointers regardless of the input size
 *
 * -----------------------------------------------------------------------------
 */

bool hasCycle(ListNode *head) {
	if (head == nullptr) {
		return false;
	}
	
	ListNode* slow{head};
	ListNode* fast{head};
	bool result{false};

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			result = true;
			break;
		}
	}
	return result;
}
