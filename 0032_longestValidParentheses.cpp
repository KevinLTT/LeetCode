#include "u.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> Stack;
        int longest = 0;
        int length = 0;
        for( int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '(' )
                Stack.push( s[i] );
            else if( s[i] == ')' )
            {
                if( Stack.empty() )
                {
                    if( length > longest )
                        longest = length;
                    length = 0;
                }
                else
                {
                    Stack.pop();
                    length += 2;
                }
            }
        }
        if( length > longest )
            longest = length;

        return longest;
    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.longestValidParentheses( str ) << endl;
}
