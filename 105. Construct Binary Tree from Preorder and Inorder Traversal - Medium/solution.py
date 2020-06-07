# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if inorder:
            ind = inorder.index(preorder.pop(0))
            return TreeNode(inorder[ind], 
                            self.buildTree(preorder, inorder[0:ind]),
                            self.buildTree(preorder, inorder[ind+1:])
                           )