class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        if len(grid) < 0 or len(grid[0]) < 0:
            return 0;

        height = len(grid)
        width = len(grid[0])
        
        for row in range(1, height):
            grid[row][0] = grid[row][0] + grid[row-1][0]
        for col in range(1, width):
            grid[0][col] = grid[0][col] + grid[0][col-1]
            
        def update(mat, y, x):
            mat[y][x] = mat[y][x] + ( mat[y-1][x] if mat[y-1][x] <= mat[y][x-1] else mat[y][x-1] )
            
        for dia in range(1, height if height < width else width):
            update(grid, dia, dia)
            for row in range(dia+1, height):
                update(grid, row, dia)
            for col in range(dia+1, width):
                update(grid, dia, col)
                

        return grid[-1][-1]    
