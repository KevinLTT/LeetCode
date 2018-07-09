#include "u.h"

class Solution {
public:
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n;
        if( m <= 0 )
            return 0;
        else
        {
            n = obstacleGrid[0].size();
            if( n <= 0 )
                return 0;
        }

        if( obstacleGrid[0][0] == 1 )
            return 0;
        else
            obstacleGrid[0][0] = 1;

        auto dp = obstacleGrid;
        for( int col = 1; col < n; col++ )
        {
            if( dp[0][col] == 1 )
                dp[0][col] = 0;
            else
                dp[0][col] = dp[0][col-1];
        }
        for( int row = 1; row < m; row++ )
        { 
            if( dp[row][0] == 1 )
                dp[row][0] = 0;
            else
                dp[row][0] = dp[row-1][0];
        }

        for(int dia = 1; dia < m and dia < n; dia++)
        {
            if( dp[dia][dia] == 1 )
                dp[dia][dia] = 0;
            else
                dp[dia][dia] = dp[dia-1][dia] + dp[dia][dia-1];
            for( int col = dia+1; col < n; col++ )
                if( dp[dia][col] == 1 )
                    dp[dia][col] = 0;
                else
                    dp[dia][col] = dp[dia][col-1] + dp[dia-1][col];
            for( int row = dia+1; row < m; row++ )
                if( dp[row][dia] == 1 )
                    dp[row][dia] = 0;
                else
                    dp[row][dia] = dp[row][dia-1] + dp[row-1][dia];
        }

        return dp[m-1][n-1];
    }
};

int main()
{
    Solution s;

    return 0;
}
