# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def right(self, root: Optional[TreeNode], path: List[int], curr_depth: int, maxDepth: List[int]):
        if root is None:
            return

        if curr_depth > maxDepth[0]:
            maxDepth[0] = curr_depth
            path.append(root.val)

        if root.right:
            self.right(root.right, path, curr_depth + 1, maxDepth)
        
        if root.left:
            self.right(root.left, path, curr_depth + 1, maxDepth)

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        path = []
        maxDepth = [-1]  # Using a list to allow mutation in recursion
        self.right(root, path, 0, maxDepth)
        return path
        