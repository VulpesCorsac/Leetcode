"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':

        visited = {}

        def cloneHelper(node):
            if node and node not in visited:
                newNode = Node(node.val)
                visited[newNode.val] = newNode
                newNode.neighbors = [visited.get(n.val) or cloneHelper(n) for n in node.neighbors]
                return newNode

        return cloneHelper(node)