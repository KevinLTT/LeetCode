class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for( int diagonalIndex = 0; diagonalIndex < matrix.size()/2; diagonalIndex++ )
        {
            int row = diagonalIndex;
            for( int col = diagonalIndex; col < matrix.size() - diagonalIndex - 1; col++ )
            {
                int i = row, j = col;
                int temp, pre = matrix[i][j];
                for( int k = 0; k < 4; k++ )
                {
                    int iNew = j;
                    int jNew = matrix.size()-i-1;
                    temp = matrix[iNew][jNew];
                    matrix[iNew][jNew] = pre;
                    pre = temp;
                    i = iNew;
                    j = jNew;
                }
            }
            
        }
    }
};
