class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        
        tail = m + n - 1
        tail1 = m - 1
        tail2 = n - 1
        
        while tail1 >= 0 and tail2 >= 0:
            if nums1[tail1] > nums2[tail2]:
                nums1[tail] = nums1[tail1]
                tail1 -= 1
            else:
                nums1[tail] = nums2[tail2]    
                tail2 -= 1
            tail -= 1    
        
        while tail2 >= 0:
            nums1[tail] = nums2[tail2]
            tail -= 1
            tail2 -= 1
            
