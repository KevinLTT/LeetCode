class Solution {
public:
    void permQueens( int& res, vector<bool>& columnOccupied, vector<bool>& splashOccupied, vector<bool>& backsplashOccupied, int row )
    {
        int N = columnOccupied.size();
        
        if(row >= N)
        {
            res++;
            return;
        }            
        
        for( int col = 0; col < N; col++)
        {
            if( !columnOccupied[col] && !splashOccupied[col+row] && !backsplashOccupied[N-1+row-col] )
            {
                columnOccupied[col] = true;
                splashOccupied[col+row] = true;
                backsplashOccupied[N-1+row-col] = true;
                permQueens( res, columnOccupied, splashOccupied, backsplashOccupied, row+1 );
                columnOccupied[col] = false;
                splashOccupied[col+row] = false;i
                backsplashOccupied[N-1+row-col] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> columnOccupied(n, false);
        vector<bool> splashOccupied(n, false);
        vector<bool> backsplashOccupied(n, false);
        permQueens(res, columnOccupied, splashOccupied, backsplashOccupied, 0);
        return res;    
    }
};
