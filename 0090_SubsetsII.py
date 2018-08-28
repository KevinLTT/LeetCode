class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        def sub(nums, current, index, reses):
            print(current, index)
            
            if index >= len(nums):
                reses.append(current.copy())
                return
            
            count = 1
            initial_index = index
            pre = nums[index]
            while index + 1 < len(nums) and pre == nums[index+1]:
                count += 1
                pre = nums[index+1]
                index += 1
                
            sub(nums, current, index+1, reses)    
            for i in range(count):
                current.append(nums[initial_index])
                sub(nums, current, index+1, reses)
            for i in range(count):
                current.pop()
            
        if not nums:
            return list([])
        
        reses = list()
        current = list()
        nums.sort()
        sub(nums, current, 0, reses)

        return reses
