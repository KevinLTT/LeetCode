# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """

        stack = list()
        if not root:
            return False
        else:
            stack.append((root, root.val))    
        
        ans = False
        while stack:
            node, total_val = stack.pop()
            if not node.left and not node.right:
                if total_val == sum:
                    ans = True
                    break
            else:
                if node.left:
                    stack.append((node.left, total_val + node.left.val))    
                if node.right:
                    stack.append((node.right, total_val + node.right.val))    
        
        return ans
