# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        if not root:
            return []
        
        res = [[]]
        current_level = [root]
        next_level = []
        level_index = 0
        state = ['left', 'right']
        direction = state[level_index % 2]
        
        while current_level:
            node = current_level.pop()
            if node:
                res[level_index].append(node.val)
                if direction == 'left':
                    if node.left:
                        next_level.append(node.left)
                    if node.right:    
                        next_level.append(node.right)
                else:
                    if node.right:
                        next_level.append(node.right)
                    if node.left:    
                        next_level.append(node.left)    
            
            if not current_level:
                if next_level:
                    level_index += 1
                    direction = state[level_index % 2]
                    res.append([])
                    current_level = next_level.copy()
                    next_level = []
        
        return res
