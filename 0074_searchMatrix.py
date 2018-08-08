class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        def bi_search(l, target):
            left, right = 0, len(l)-1
            find = False
            while left <= right:
                mid = (left + right) // 2
                if l[mid] == target:
                    find = True 
                    break
                elif l[mid] < target:
                    left = mid + 1
                elif l[mid] > target:
                    right = mid - 1    
            return find        
        
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        find = False
        pre = -1
        target_row = -2
        for idx, row in enumerate(matrix):
            if row[0] > target:
                target_row = pre
                break
            elif row[0] == target:
                find = True
                break
            else:
                pre = idx
        
        if find is True:
            return True
        elif target_row == -1:
            return False
        elif target_row == -2:
            return bi_search(matrix[-1], target)
        else:
            return bi_search(matrix[target_row], target)
