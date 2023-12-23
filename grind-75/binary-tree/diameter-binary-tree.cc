/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/diameter-of-binary-tree/
 * 
 * Solution Description:
 * We will use recursive DFS to traverse our tree bottom-up. In doing so we will
 * consider all possible paths and update a variable to hold the overall max
 * path which will be our diameter.
 *
 * Steps:
 * 1 - Implement a DFS function that also takes a int ref input, this is the
 *     value we will be updating
 * 2 - On each iteration our DFS function should update the integer value if
 *     a wider diameter (i.e. left + right > curr_max) has been found
 * a - Then, since we are going bottom up, we need to return the current max
 *     path length so we return max(left + right) + 1
 * 3 - When our DFS concludes our integer variable will hold our diameter
 * NOTE: Our initial function call starts from root but the longest path doesn't
 * need to pass through the root node, therefore we discard the return value.
 *
 * Complexity Analysis:
 * Time: O(n+m) because we are traversing all nodes and edges
 * Space: O(h) where h is the height of the tree because that will be the max
 * number of items on our call stack at any given time.
 *
 * -----------------------------------------------------------------------------
 */

int search(TreeNode* node, int& curr_max) {
  if (node == nullptr) {
    return 0;
  }
  int left{search(node->left, curr_max)};
  int right{search(node->right, curr_max)};
  curr_max = std::max(curr_max, left + right);
  return 1 + std::max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  int diameter{0};
  search(root, diameter); // We don't return this value because it includes the
                          // the root node which isn't a requirement
  return diameter;
}

