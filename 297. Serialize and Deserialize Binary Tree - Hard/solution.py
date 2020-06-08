# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: 'TreeNode') -> str:
        def helper(node: 'TreeNode') -> None:
            if node:
                ans.append(str(node.val))
                helper(node.left)
                helper(node.right)
            else:
                ans.append('#')
        
        ans = []
        helper(root)
        return ' '.join(ans)
        
    def deserialize(self, data: str) -> 'TreeNode':
        def helper() -> 'TreeNode':
            value = next(values)
            
            if value == '#':
                return None
            
            node = TreeNode(int(value))
            node.left  = helper()
            node.right = helper()
            
            return node
        
        values = iter(data.split())
        
        return helper()

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))