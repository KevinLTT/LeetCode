class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        
        if len(nums) <= 1:
            return

        zero_next_pos = 0    
        two_next_pos = len(nums)-1    
        
        idx = 0
        while idx <= two_next_pos:
            if nums[idx] == 0:
                nums[zero_next_pos], nums[idx] = nums[idx], nums[zero_next_pos]
                zero_next_pos += 1
                idx += 1
            elif nums[idx] == 2:
                nums[two_next_pos], nums[idx] = nums[idx], nums[two_next_pos]    
                two_next_pos -= 1
            else:
                idx += 1    
                
        return        
