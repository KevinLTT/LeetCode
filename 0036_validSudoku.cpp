#include "u.h"

class checkBoard
{
public:
    vector<bool> valid;

    checkBoard()
    {
        valid = vector<bool>( 9, true );
    }

    bool check( const char &c )
    {
        if( c < '1' || c > '9' )
            return true;
        int num = c - '0';
        if( valid[num-1] == false )
            return false;
        else
        {
            valid[num-1] = false;
            return true;
        }
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        checkBoard rowCheck[9], colCheck[9], boxCheck[9];
        for( int i = 0; i < board.size(); i++ )
            for( int j = 0; j < board[i].size(); j++ )
            {
                auto c = board[i][j];
                if( rowCheck[i].check( c ) == false || colCheck[j].check(c) == false || boxCheck[ 3*(i/3) + j/3 ].check(c) == false )
                    return false;
            }

        return true;
    }
};
