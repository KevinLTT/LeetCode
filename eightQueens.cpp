#include "u.h"

void queen( vector<vector<bool>>& board, int i, vector<vector<vector<bool>>>& res )
{
    if( i >= board.size() )
        res.push_back( board );


    //if( board[0][3] == true && board[1][6])
        //cout << "haha" << endl;

    for( int col = 0; col < board[0].size(); col++ )
    {
        //if( i==7 && board[6][0] && board[5][4] && board[4][1] && board[3][7] && board[0][3] == true && board[1][6] && board[2][2] )
            //cout << "haha" << endl;

        bool valid = true;
        for( int row = i-1; row >= 0; row-- )
        {
            if( board[row][col] == true )
            {
                valid = false;
                break;
            }
            if( i-row+col < board[0].size() && board[row][i-row+col] == true )
            {
                valid = false;
                break;
            }
            if( col-i+row >= 0 && board[row][col-i+row] == true )
            {
                valid = false;
                break;
            }
        }
        if( valid == true )
        { 
            board[i][col] = true;
            queen( board, i+1, res );
            board[i][col] = false;
        }
    }
}

void printBoard( vector<vector<bool>> board )
{
    cout << "------------------------------------" << endl;
    for( auto a : board )
    {
        for( auto b : a )
            cout << ( b ? "1  " : "0  " );
        cout << endl;
    }
}

int main()
{
    vector<vector<bool>> board;
    for( int i = 0; i < 8; i++ )
        board.push_back( vector<bool>( 8, false ) );
    printBoard( board );

    vector<vector<vector<bool>>> res;
    queen( board, 0, res );
    cout << res.size() << endl;
    //for( auto a : res )
    //{
        //cout << "-----------------" << endl;
        //for( auto b : a )
        //{
            //for( auto c : b )
                //cout << ( c ? "1 ": "0 ");
            //cout << endl;
        //}
    //}
}
