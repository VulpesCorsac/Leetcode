# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, last: int) -> List[TreeNode]:
        return self.generateTreesHelper(1, last) if last else []

    @functools.lru_cache(None)
    def generateTreesHelper(self, first: int, last: int) -> List[TreeNode]:
        return [TreeNode(root, left, right)
                for root  in range(first, last+1)
                for left  in self.generateTreesHelper(first, root-1)
                for right in self.generateTreesHelper(root+1, last )] or [None]