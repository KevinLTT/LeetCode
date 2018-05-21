#include "u.h"

class Solution {
public:
    inline bool indexValid( string s, int i )
    {
        if( s.empty() || i >= s.size() || i < 0 )
            return false;
        else
            return true;
    }

    inline bool pair( string s, int i, int j )
    {
        if( !indexValid( s, i ) || !indexValid( s, j ) )
            return false;

        if( s[i] == '(' && s[j] == ')' )
            return true;
        else
            return false;
    }

    inline void checkAdjacent( string s, vector<int> &valid, int pre, int begin, int end )
    {
        if( !indexValid( s, pre ) || !indexValid( s, begin ) || !indexValid( s, end ) )
            return; 

        int sentinal = -1 * s.size();
        if( valid[pre] > sentinal && valid[pre] <= 0 && valid[begin] > 0 )
        {
            int preBegin = -1 * valid[pre];
            valid[preBegin] = valid[preBegin] + valid[begin];
            valid[end] = valid[pre];
        }
    }

    int longestValidParentheses(string s) {
        if( s.empty() )
            return 0;

        int sentinal = -1 * (int)s.size();
        vector<int> valid( s.size(), sentinal );
        int longest = 0;

        for( int i = 0; i < s.size(); i++ )
        {
            if( valid[i] <= sentinal )
            {
                if( i-1 >= 0 && valid[i-1] <= sentinal  )
                {
                    if( pair( s, i-1, i ) )
                    {
                        valid[i-1] = 2;
                        valid[i] = -( i-1 );
                        checkAdjacent( s, valid, i-2, i-1, i );
                    }
                }
                else if( i-1 >= 0 && valid[i-1] > sentinal )
                {
                    int pre = -valid[i-1]-1;
                    if( pre >= 0 && valid[pre] <= sentinal && pair( s, pre, i ) )
                    {
                        valid[i] = -pre;
                        valid[pre] = valid[pre+1] + 2;
                        checkAdjacent( s, valid, pre-1, pre, i );
                    }
                }
            }
            if( valid[i] > sentinal && valid[-1*valid[i]] > longest )
                longest = valid[-1*valid[i]];
        }

        return longest;
    }
};

int main()
{
    Solution s;
    //           0123456789012345678901234
    //string str( ")(((((()())()()))()(()))(" );
    string str( "()()(()(((()))()))()))))()(())))()(()())()()()))())))())())))(()()()))))()((()(())(())))((()())(()()()((((()(())))))((()()((())(())(()(())))))()()())(())(()())((()())()(((())))()(()()))" );
    //string str( "()" );
    //cin >> str;
    cout << s.longestValidParentheses( str ) << endl;
}
