# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

class TreeNode:
    def __init__(self, x: int):
        self.val = x
        self.left = None
        self.right = None

def lowestCommonAncestor(root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    if None in [root, p, q]:
        return None
    if root.val < p.val and root.val < q.val:
        return lowestCommonAncestor(root=root.right, p=p, q=q)
    if p.val < root.val and q.val < root.val:
        return lowestCommonAncestor(root=root.left, p=p, q=q)
    return root
