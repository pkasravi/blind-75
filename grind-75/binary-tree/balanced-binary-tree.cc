#include <iostream>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/balanced-binary-tree/
 * 
 * Solution Description:
 * We will traverse the tree using recursive DFS. Then in a bottom up manner we
 * will determine if each subtree is balanced by comparing the height of each
 * left and right subtree. This isBalanced property will bubble up to the root
 * to give us our final answer.
 *
 * Steps:
 * 1 - Define a recursive DFS helper function
 * a - When the function encounters null it should return (True, 0)
 * b - Otherwise the balanced boolean comes from calculating the absdiff between
 *     the heights of the left and right nodes if it is <= 1 then balanced is True
 * 2 - Call our helper function from our root and the returned boolean will be
 * 		 our final answer, we discard the final height
 *
 * Complexity Analysis:
 * Time: O(n) because in the worst case we traverse every node in the tree
 * Space: O(h) where h is the height of the tree, because in the worst case our
 * call stack grows to h for each level of the tree.
 *
 * -----------------------------------------------------------------------------
 */

struct SearchResult {
  bool balanced;
  int height;
};

SearchResult dfs(TreeNode* node) {
  if (node == nullptr) {
    return {true, 0};
  }
  const auto left{dfs(node->left)};
  const auto right{dfs(node->right)};
  return {
    left.balanced && right.balanced && std::abs(left.height - right.height) <= 1,
    std::max(left.height, right.height) + 1
  };
}

bool isBalanced(TreeNode* root) {
  return dfs(root).balanced;
}
