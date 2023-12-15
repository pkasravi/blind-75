
/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * 
 * Solution Description:
 * Using the sorted property of a BST, we can compare our root to p and q. The 
 * goal is to move down the tree until we reach a node that lies in between the
 * values of p and q. So if p and q are both less than a node, we move to the
 * left otherwise we move to the right until a match is found.
 *
 * Steps:
 * 1 - If root is null return null (edge case)
 * 2 - Our base case is if root is lte q and gte p or vice versa, we return root
 * 3 - If root is greater than p and q, recurse using the current root's left in
 *     the function call
 * 4 - If root is less than p and q recurse using the current root's right
 *
 * Complexity Analysis:
 * Time: O(logn) because in the worst case we still continuously split the tree
 * Space: O(logn) for our call stack
 *
 * -----------------------------------------------------------------------------
 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr || p == nullptr || q == nullptr) {
		return nullptr;
	}
	if (root->val < p->val && root->val < q->val) {
		return lowestCommonAncestor(root->right, p, q);
	}
	if (p->val < root->val && q->val < root->val) {
		return lowestCommonAncestor(root->left, p, q);
	}
	return root;
}
