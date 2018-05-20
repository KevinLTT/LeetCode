#include "u.h"

class Solution {
public:
    bool pair( string s, int i, int j )
    {
        if( i >= s.size() || j >= s.size() )
            return false;

        if( s[i] == '(' && s[j] == ')' )
            return true;
        else
            return false;
    }

    int longestValidParentheses(string s) {
        if( s.empty() )
            return 0;

        vector<int> valid( s.size(), -1 );
        for( int i = 0; i < s.size()-1; i++ )
            if( pair( s, i, i+1 ) )
            {
                valid[i] = 2;
                valid[i+1] = i;
            }

        int longest = 0;
        while( 1 )
        {
            bool find = false;
            
            bool preValid = false;
            int length = 0;
            int begin = -1;
            for( int i = 0; i < s.size(); i++ )
            {
                if( valid[i] >= 0 )
                {
                    if( i-1 >= 0 && valid[i-1] < 0 )
                    {
                        begin = i;
                        length = 1;
                    }
                    else
                    {
                        length++;
                        valid[begin] = length;
                        valid[i] = begin;
                    }
                }
                else if( i-1 >= 0 && valid[i-1] >= 0 )
                {
                    if( begin-1 >= 0 && i < s.size() && pair( s, begin-1, i ) )
                    {
                        valid[i] = begin-1;
                        valid[begin-1] = valid[begin]+2;
                        length += 2;
                        begin = begin-1;
                        if( begin-1 >= 0 && valid[begin-1] >= 0 )
                        {
                            valid[i] = valid[begin-1];
                            valid[valid[i]] = valid[valid[i]] + valid[begin];
                            begin = valid[i];
                            length = valid[valid[i]];
                        }
                    }
                    else
                    {
                        if( length > longest )
                        {
                            find = true;
                            longest = length;
                        }

                        length = 0;
                    }
                }
            }

            if( length > longest )
            {
                find = true;
                longest = length;
            }

            if( !find )
                break;
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
