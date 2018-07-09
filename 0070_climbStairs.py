class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        prepre = 0
        pre = 1
        for step in range(0, n):
            steps = pre + prepre
            prepre = pre
            pre = steps
        return steps   
            
