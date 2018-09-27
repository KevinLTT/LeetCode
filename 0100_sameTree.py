# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraverse(self, p, q):
        if p and not q:
            return False
        elif q and not p:
            return False
        elif p and q and p.val != q.val:
            return False
        elif not p and not q:
            return True
        
        return self.inorderTraverse(p.left, q.left) and self.inorderTraverse(p.right, q.right)
    
    def inorder(self, p, q):
        from collections import deque
        d1 = deque()
        d2 = deque()
        
        d1.append(p)
        d2.append(q)
        ans = True
        while d1 and d2:
            np = d1.popleft()
            nq = d2.popleft()
            if np and nq:
                if np.val != nq.val:
                    ans = False
                    break
                else:
                    d1.append(np.left)
                    d1.append(np.right)
                    d2.append(nq.left)
                    d2.append(nq.right)
            elif not np and not nq:
                continue    
            else:
                ans = False    
                break
        return ans        

    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        
        return self.inorder(p, q)
        return self.inorderTraverse(p, q)
