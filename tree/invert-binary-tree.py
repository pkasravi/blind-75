# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from collections import deque
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root:
        return None
    bfs_queue = deque()
    bfs_queue.append(root)

    while len(bfs_queue) > 0:
        current_node = bfs_queue.popleft()
        if current_node.left:
            bfs_queue.append(current_node.left)
        if current_node.right:
            bfs_queue.append(current_node.right)
        current_node.left, current_node.right = current_node.right, current_node.left
    return root
