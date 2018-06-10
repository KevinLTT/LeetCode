#include "u.h"

class Solution {
public:
    void permQueens( vector<vector<string>>& res, vector<bool>& columnOccupied, vector<bool>& splashOccupied, vector<bool>& backsplashOccupied, vector<string>& perm, int row )
    {
        int N = columnOccupied.size();
        
        if(row >= N)
        {
            res.push_back(perm);
            return;
        }            
        
        for( int col = 0; col < N; col++)
        {
            if( !columnOccupied[col] && !splashOccupied[col+row] && !backsplashOccupied[N-1+row-col] )
            {
                columnOccupied[col] = true;
                splashOccupied[col+row] = true;
                backsplashOccupied[N-1+row-col] = true;
                string rowPerm( N, '.');
                rowPerm[col] = 'Q';
                perm.push_back(rowPerm);
                permQueens( res, columnOccupied, splashOccupied, backsplashOccupied, perm, row+1 );
                perm.pop_back();
                columnOccupied[col] = false;
                splashOccupied[col+row] = false;
                backsplashOccupied[N-1+row-col] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> columnOccupied(n, false);
        vector<bool> splashOccupied(n, false);
        vector<bool> backsplashOccupied(n, false);
        vector<string> perm;
        permQueens(res, columnOccupied, splashOccupied, backsplashOccupied, perm, 0);
        return res;    
    }
};
