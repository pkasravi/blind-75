/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * 
 * Solution Description:
 * For this solution we will utilize iterative BFS to traverse the tree in a top
 * down manner. As we continue traversing the tree we will increment a counter
 * until our main loop breaks due to an empty work queue or no more nodes in the
 * tree to traverse.
 *
 * Steps:
 * 1 - Set up boilerplate BFS algorithm
 * 2 - Since each iteration of the main while loop represents a level of the
 *     tree we can simply increment a counter for each loop.
 * 3 - Return our counter
 *
 * Complexity Analysis:
 * Time: O(n) because we traverse all nodes for BFS
 * Space: O(n) since in the worst case we hold all nodes in the queue
 *
 * -----------------------------------------------------------------------------
 */

int maxDepth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}

	std::queue<TreeNode*> work_buffer{{root}};
	int depth{0};

	while (!work_buffer.empty()) {
		int level_size = work_buffer.size();
		for (;level_size > 0; --level_size) {
		  const auto current{work_buffer.front()};
		  work_buffer.pop();
		  if (current->left != nullptr) {
		  	work_buffer.push(current->left);
		  }
		  if (current->right != nullptr) {
		  	work_buffer.push(current->right);
		  }
		}
		++depth;
	}
	return depth;
}

int maxDepthRecursive(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  const int left{maxDepth(root->left)};
  const int right{maxDepth(root->right)};
  return std::max(left, right) + 1;
}

