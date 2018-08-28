class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        
        def find_pivot(nums):
            if not nums:
                print('nums is empty')
                return None

            pivot = 0
            left = 0
            right = len(nums) - 1
            while left <= right:
                mid = (left + right) // 2
                if mid - 1 >= 0:
                    if nums[mid] < nums[mid-1]:
                        pivot = mid
                        break
                    elif nums[mid] > nums[right]:
                        left = mid + 1
                    elif nums[mid] < nums[left]:
                        right = mid - 1    
                    else:
                        for index in range(left, right+1):
                            if nums[index] < nums[index-1]:
                                pivot = index
                                break
                        break   
                else:
                    if mid + 1 < len(nums) and nums[mid] > nums[mid+1]:
                        pivot = 1
                    else:
                        pivot = 0
                    break
            
            return pivot
        
        if not nums:
            return False
        
        pivot = find_pivot(nums)
        index_mapping = dict()
        for index in range(len(nums)):
            index_mapping[index] = pivot + index - len(nums)*((pivot + index) // len(nums))
        
        left = 0
        right = len(nums) - 1
        pos = -1
        while left <= right:
            mid = (left + right) // 2
            mid_mapping = index_mapping[mid]
            if nums[mid_mapping] == target:
                pos = mid_mapping
                break
            elif nums[mid_mapping] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        return pos >= 0
        
