# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if not root or root.val == x or root.val == y:
            return False
    
        queue = deque([root])
               
        while queue:
            size = len(queue)
            is_x_exist = False
            is_y_exist = False
            for _ in range(size):
                node = queue.popleft()
                if node.val == x:
                    is_x_exist = True
                elif node.val == y:
                    is_y_exist = True
                
                if node.left and node.right:
                    if set([node.left.val, node.right.val]) == set([x, y]):
                        return False
                if node.left: 
                    queue.append(node.left)
                if node.right: 
                    queue.append(node.right)
            if is_x_exist and is_y_exist:
                return True

        return False