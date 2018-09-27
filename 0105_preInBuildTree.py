# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        
        if not preorder:
            return None
        
        root = TreeNode(preorder[0])
        root_inorder_index = inorder.index(root.val)
        left_num = root_inorder_index
        right_num = len(inorder) - root_inorder_index - 1
        root.left = self.buildTree(preorder[1:left_num+1], inorder[0:root_inorder_index])
        root.right = self.buildTree(preorder[left_num+1:], inorder[root_inorder_index+1:])
        
        return root
                
