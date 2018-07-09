class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        left = 0
        right = x 
        while left <= right:
            mid = (left + right) // 2
            if mid ** 2 == x:
                break
            elif mid ** 2 > x:
                right = mid - 1;
            else:
                left = mid + 1
        if mid ** 2 > x:
            mid -= 1
        return mid   
