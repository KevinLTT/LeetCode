#include "u.h"

#define PUSH 0
#define POP 1

class Solution {
    public:
        vector<string> gen( stack<char> s, int type, int rest )
        {
            vector<string> res;
            if( rest <= 0 && s.empty() )
                return res;
            if( type == PUSH && rest <= 0 )
                return res;
            if( type == POP && s.empty() )
                return res;

            if( type == PUSH )
                s.push( '(' );
            else
                s.pop();

            vector<string> resPush = gen( s, PUSH, rest-1 );
            vector<string> resPop = gen( s, POP, rest );
            string c = ( type == PUSH ) ? "(" : ")";
            for( auto str : resPush )
                res.push_back( c + str );
            for( auto str : resPop )
                res.push_back( c + str );
            if( resPush.empty() && resPop.empty() )
                res.push_back( c );
            
            return res;
        }

        vector<string> generateParenthesis(int n) {
            stack<char> s;
            return gen( s, PUSH, n );
        }
};

int main()
{
    Solution s;
    auto res = s.generateParenthesis( 3 );
    cout << res.size() << endl;
    for( auto str : res )
        cout << str << endl;

    return 0;
}

