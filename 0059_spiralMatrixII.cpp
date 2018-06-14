#include "u.h"


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int available = 0x0abcdef1;
        vector<vector<int>> mat;
        for( int i = 0; i < n; i++ )
            mat.push_back( vector<int>( n, available ) );

        int state = 0;
        int yDir[4] = {0, 1, 0, -1};
        int xDir[4] = {1, 0, -1, 0};
        int x = -1, y = 0;
        for( int i = 1; i <= n*n; i++ )
        {
            int xNew = x + xDir[state];
            int yNew = y + yDir[state];
            if( xNew >= n or yNew >= n or mat[yNew][xNew] != available )
            {
                state = (state + 1) % 4;
                xNew = x + xDir[state];
                yNew = y + yDir[state];
            }
            x = xNew;
            y = yNew;
            mat[y][x] = i;
        }
        return mat;
    }
};

int main()
{
    Solution s;
    auto mat = s.generateMatrix( 3 );
    for( auto row : mat )
    { 
        for( auto value : row )
            cout << value << ", ";
        cout << endl;
    }
}
