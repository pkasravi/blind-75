# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def search(node: Optional[TreeNode], curr_max: List[int]) -> int:
    if not node:
        return 0
    left = search(node.left, curr_max)
    right = search(node.right, curr_max)
    curr_max[0] = max(curr_max[0], left + right)
    return 1 + max(left, right)

def diameterOfBinaryTree(root: Optional[TreeNode]) -> int:
    if not root:
        return 0
    diameter = [0]
    search(root, diameter)
    return diameter[0]
