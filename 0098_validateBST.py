# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def validate(self, node, min_val, max_val):
        if node is None:
            return True
        elif (min_val is not None and node.val <= min_val) or (max_val is not None and node.val >= max_val):
            return False
        elif self.validate(node.left, min_val, node.val) is False:
            return False
        elif self.validate(node.right, node.val, max_val) is False:
            return False
        else:
            return True
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.validate(root, None, None)
