"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None

        node = head
        while node:
            copy = Node(node.val, node.next, None)
            node.next = copy
            node = copy.next

        node = head
        while node:
            if node.random:
                node.next.random = node.random.next
            node = node.next.next

        node = head
        copy = copy_head = head.next
        while node:
            node.next = copy.next
            node = node.next

            if node:
                copy.next = node.next
                copy = copy.next

        return copy_head