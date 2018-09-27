# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        
        def gen(nums):
            if not nums:
                return [None]
            
            roots = []
            for idx in range(len(nums)):
                lefts = gen(nums[:idx])
                rights = gen(nums[idx+1:])
                for left in lefts:
                    for right in rights:
                        root = TreeNode(nums[idx])
                        root.left = left
                        root.right = right
                        roots.append(root)
                
            return roots    
                
        nums = [x for x in range(1, n+1)]
        return gen(nums)
