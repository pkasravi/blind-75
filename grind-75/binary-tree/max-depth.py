# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def maxDepth(root: Optional[TreeNode]) -> int:
    if not root:
        return 0

    depth = 0
    work_buffer = deque([root])

    while len(work_buffer) > 0:
        level_size = len(work_buffer)
        for _ in range(level_size):
            current = work_buffer.popleft()
            if current.left:
                work_buffer.append(current.left)
            if current.right:
                work_buffer.append(current.right)
        depth += 1
    return depth


def maxDepthRecursive(root: Optional[TreeNode]) -> int:
    if not root:
        return 0
    return max(maxDepth(root.left), maxDepth(root.right)) + 1
