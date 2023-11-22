#include <queue>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/invert-binary-tree/description/
 * 
 * Solution Description:
 * We will perform BFS to traverse the tree and every node that has children, we
 * will swap the left and right children and at the end of doing so we will
 * invert the whole tree.
 *
 * Steps:
 * 1 - Create a queue and insert our root
 * 2 - Use the queue to perform BFS
 * 3 - In our while loop, after pushing children of the current node into our
 * queue, swap the left and right pointers for the current node
 * 4 - Return the same root we received as input
 *
 * Complexity Analysis:
 * Time: O(n) because we must process every node to invert the tree
 * Space: O(n) because due to the nature of a binary tree, the upper limit on
 * the number of nodes in our queue at any given time is O(n/2) which reduces to
 * O(n).
 *
 * -----------------------------------------------------------------------------
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    std::queue<TreeNode*> bfs_queue{{root}};
    while (!bfs_queue.empty()) {
        auto current{bfs_queue.front()};
        bfs_queue.pop();
        if (current->left != nullptr) {
            bfs_queue.push(current->left);
        }
        if (current->right != nullptr) {
            bfs_queue.push(current->right);
        }
        const auto old_left{current->left};
        current->left = current->right;
        current->right = old_left;
    }
    return root;
}

