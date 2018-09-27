# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        from collections import deque
        
        if not root:
            return []

        current_level = deque()
        current_level.append(root)
        next_level = deque()
        res = [[]]
        
        while current_level:
            node = current_level.popleft()
            if node:
                res[-1].append(node.val)
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

            if not current_level and next_level:
                res.append([])
                current_level = next_level.copy()
                next_level = deque()
                

        res.reverse()        
        return res
