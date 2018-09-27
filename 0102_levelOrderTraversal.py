# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        from collections import deque
        
        res = list()
        queue = deque()
        queue.append((1, root))
        
        while queue:
            level_index, node = queue.popleft()
            if not node:
                continue
            else:
                if level_index > len(res):
                    res.append([node.val])
                else:
                    res[level_index-1].append(node.val)
                
                queue.append((level_index+1, node.left))
                queue.append((level_index+1, node.right))
        
        return res
