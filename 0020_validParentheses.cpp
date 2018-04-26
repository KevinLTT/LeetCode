#include "u.h"

class Solution {
public:
    map< char, char > pair = 
    {
        { '(', ')' },
        { '{', '}' },
        { '[', ']' }
    };

    bool isValid(string s) {
        stack<char> pairStack;
        for( int i = 0; i < s.size(); i++ )
        {
            auto c = s[i];
            if( c == '{' || c == '(' || c == '[' )
                pairStack.push( c );

            if( c == '}' || c == ')' || c == ']' )
            {
                if( !pairStack.empty() && pair[ pairStack.top() ] == c )
                    pairStack.pop();
                else
                    return false;
            }
        }
        return pairStack.empty() ? true : false;
    }
};
