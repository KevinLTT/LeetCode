# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dig(self, node, depth):
        if not node:
            return 0
            
        if not node.left and not node.right:
            return depth    
        elif node.left and not node.right:
            return self.dig(node.left, depth+1)
        elif not node.left and node.right:
            return self.dig(node.right, depth+1)
        else:
            return min(self.dig(node.left, depth+1), self.dig(node.right, depth+1))
        
            
    
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        return self.dig(root, 1)
