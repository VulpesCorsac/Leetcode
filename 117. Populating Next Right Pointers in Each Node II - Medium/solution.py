"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        queue, first, current = root, None, None

        while queue:
            if queue.left:
                if first:
                    current.next = queue.left
                    current = current.next
                else:
                    first = current = queue.left

            if queue.right:
                if first:
                    current.next = queue.right
                    current = current.next
                else:
                    first = current = queue.right

            queue = queue.next
            if not queue and first:
                queue, first, current = first, None, None

        return root