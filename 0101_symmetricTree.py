# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def symmetric(self, p, q):
        if not p and not q:
            return True
        elif not p and q:
            return False
        elif p and not q:
            return False
        else:
            return p.val == q.val and \
                    self.symmetric(p.left, q.right) and \
                    self.symmetric(p.right, q.left)
    
    
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return not root or self.symmetric(root.left, root.right)
