class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0
        right = len(nums)-1
        begin = -1
        while( left <= right ):
            mid = (left+right)//2
            if( nums[mid] > target ):
                right = mid-1
            elif( nums[mid] < target ):
                left = mid+1
            elif( mid-1 >= 0 ) and ( nums[mid-1] == target ):
                right = mid-1
            else:
                begin = mid
                break
        if(begin == -1):
            return [-1,-1]
        
        left = 0
        right = len(nums)-1
        end = -1
        while( left <= right ):
            mid = (left+right)//2
            if( nums[mid] > target ):
                right = mid-1
            elif( nums[mid] < target ):
                left = mid+1
            elif( mid+1 < len(nums) ) and ( nums[mid+1] == target):
                left = mid+1
            else:
                end = mid
                break
        
        return [begin, end]
