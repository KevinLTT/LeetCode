class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
            return 0

        pre_num = nums[0] - 1
        next_valid_pos = 0    
        count = 0
        
        for idx in range(len(nums)):
            if nums[idx] > pre_num:
                count = 1
                nums[next_valid_pos] = nums[idx]
                next_valid_pos += 1
                pre_num = nums[idx]
            elif nums[idx] == pre_num:
                count += 1
                if count <= 2:
                    nums[next_valid_pos] = nums[idx]
                    next_valid_pos += 1
        
        return next_valid_pos
