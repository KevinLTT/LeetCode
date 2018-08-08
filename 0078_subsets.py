class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        def sub(nums, result_list, current_list, pos):
            if pos >= len(nums):
                result_list.append(current_list.copy())
                return

            sub(nums, result_list, current_list, pos+1) 
            current_list.append(nums[pos])
            sub(nums, result_list, current_list, pos+1)
            current_list.pop()
            
        result_list = list()
        current_list = list()
        pos = 0
        sub(nums, result_list, current_list, pos)
        
        return result_list    
             
