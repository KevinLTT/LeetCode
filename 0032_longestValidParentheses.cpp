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

        vector<bool> valid( s.size(), false );
        for( int i = 0; i < s.size()-1; i++ )
            if( pair( s, i, i+1 ) )
                valid[i] = valid[i+1] = true;

        int longest = 0;
        while( 1 )
        {
            bool find = false;
            
            bool preValid = false;
            int length = 0;
            int begin = -1;
            for( int i = 0; i < s.size(); i++ )
            {
                if( valid[i] )
                {
                    if( preValid == false )
                    {
                        begin = i;
                        length = 1;
                    }
                    else
                    {
                        length++;
                    }
                    preValid = true;        
                }
                else if( preValid )
                {
                    if( begin-1 >= 0 && i < s.size() && pair( s, begin-1, i ) )
                    {
                        valid[begin-1] = valid[i] = true;
                        length += 2;
                        begin = begin-1;
                        preValid = true;
                    }
                    else
                    {
                        if( length > longest )
                        {
                            find = true;
                            longest = length;
                        }

                        length = 0;
                        preValid = false;
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
    string str( ")(((((()())()()))()(()))(" );
    string str1( "()()(()(((()))()))()))))()(())))()(()())()()()))())))())())))(()()()))))()((()(())(())))((()())(()()()((((()(())))))((()()((())(())(()(())))))()()())(())(()())((()())()(((())))()(()()))" );
    //string str( "()" );
    //cin >> str;
    cout << s.longestValidParentheses( str ) << endl;
}
