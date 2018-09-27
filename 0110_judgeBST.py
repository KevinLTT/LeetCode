# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traverse(self, node, depth):
        if not node:
            return True, depth - 1
        else:
            left_balanced, left_depth = self.traverse(node.left, depth+1)
            right_balanced, right_depth = self.traverse(node.right, depth+1)
            diff = abs(left_depth - right_depth)
            return left_balanced and right_balanced and diff <= 1, max(left_depth, right_depth)
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        balanced, depth = self.traverse(root, 1)
        return balanced
