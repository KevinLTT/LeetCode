# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        
        if not inorder:
            return None
        
        root = TreeNode(postorder[-1])
        root_index = inorder.index(root.val)
        left_num = root_index
        right_num = len(inorder) - root_index - 1
        root.left = self.buildTree(inorder[0:root_index], postorder[0:left_num])
        root.right = self.buildTree(inorder[root_index+1:], postorder[left_num:-1])
        
        return root
        
