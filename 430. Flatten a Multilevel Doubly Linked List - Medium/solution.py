"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        curr, stack = head, [];
        while curr:
            if curr.child:
                if curr.next:
                    stack.append(curr.next);
                curr.next, curr.child.prev, curr.child = curr.child, curr, None;
            if not curr.next and stack:
                temp = stack.pop();
                temp.prev, curr.next = curr, temp;
            curr = curr.next;
        return head;