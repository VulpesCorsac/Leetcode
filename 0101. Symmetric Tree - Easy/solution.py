# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def check(L,R):
            if L and R and L.val == R.val:
                return check(L.left, R.right) and check(L.right, R.left)
            return L == R

        return not root or check(root.left, root.right)