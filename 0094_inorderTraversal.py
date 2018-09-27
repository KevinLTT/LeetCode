# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        
        res = []
        q = []
        q.append(root)
        
        while q:
            node = q.pop()
            if not node:
                continue
                
            if isinstance(node, int):
                res.append(node)
            else:
                q.append(node.right)    
                q.append(node.val)
                q.append(node.left) 
        
        return res
