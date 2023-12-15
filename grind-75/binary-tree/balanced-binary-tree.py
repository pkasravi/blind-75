# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class SearchResult:
    def __init__(self, balanced: bool, height: int):
        self.balanced = balanced
        self.height = height

class Solution:
    def dfs(self, node: Optional[TreeNode]) -> SearchResult:
        if not node:
            return SearchResult(balanced=True, height=0)
        left, right = self.dfs(node=node.left), self.dfs(node=node.right)
        return SearchResult(
            balanced=left.balanced and right.balanced and abs(left.height - right.height) <= 1,
            height=max(left.height, right.height) + 1
        )

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root).balanced
