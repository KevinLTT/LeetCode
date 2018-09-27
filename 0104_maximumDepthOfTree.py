# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dig(self, node, depth):
        if not node:
            return depth-1
        else:
            return max(self.dig(node.left, depth+1), self.dig(node.right, depth+1))
    
    def maxDepth(self, root):
        
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dig(root, 1)
