class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        
        if not matrix or not matrix[0]:
            return

        first_row = [matrix[0][i] for i in range(len(matrix[0]))]
        first_row_zero = True if 0 in first_row else False
        first_col = [matrix[i][0] for i in range(len(matrix))]
        first_col_zero = True if 0 in first_col else False
        
        for y in range(1, len(matrix)):
            for x in range(1, len(matrix[0])):
                if matrix[y][x] == 0:
                    matrix[0][x] = 0
                    matrix[y][0] = 0
        
        for x in range(1, len(matrix[0])):
            if matrix[0][x] == 0:
                for y in range(1, len(matrix)):
                    matrix[y][x] = 0
        for y in range(1, len(matrix)):
            if matrix[y][0] == 0:
                for x in range(1, len(matrix[0])):
                    matrix[y][x] = 0
        
        if first_row_zero is True:
            for x in range(0, len(matrix[0])):
                matrix[0][x] = 0
        if first_col_zero is True:
            for y in range(0, len(matrix)):
                matrix[y][0] = 0     
