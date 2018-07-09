#include "u.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        if( m <= 0 or n <= 0 )
            return 0;

        vector<vector<int>> dp;
        for( int row = 0; row < m; row++ )
            dp.push_back(vector<int>(n, 0));
        for( int col = 0; col < n; col++ )
            dp[0][col] = 1;
        for( int row = 1; row < m; row++ )
            dp[row][0] = 1;

        for(int diagonal = 1; diagonal < m and diagonal < n; diagonal++)
        {
            dp[diagonal][diagonal] = dp[diagonal-1][diagonal] + dp[diagonal][diagonal-1];
            for( int col = diagonal+1; col < n; col++ )
                dp[diagonal][col] = dp[diagonal][col-1] + dp[diagonal-1][col];
            for( int row = diagonal+1; row < m; row++ )
                dp[row][diagonal] = dp[row][diagonal-1] + dp[row-1][diagonal];
        }

        return dp[m-1][n-1];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 2) << endl;

    return 0;
}
