class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        left = 0
        right = len(nums)-1
        index = -1
        while( left <= right ):
            mid = (left+right)//2
            if( nums[mid] < target ):
                left = mid + 1
            elif( nums[mid] > target ):
                right = mid - 1
            else:
                index = mid
                break
        if( index == -1 ):
            index = left
        return index 
        
