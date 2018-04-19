#include "u.h"

class Solution {
public:
    bool grep( string s, string p )
    {
        if( s.empty() && p.empty() )
            return true;

        bool star = false;
        if( p.size() >= 2 && p[1] == '*' )
            star = true;

        if( star == false )
        {
            if( !s.empty() && !p.empty() && ( s[0] == p[0] || p[0] == '.'  ) )
                return grep( s.substr( 1 ), p.substr( 1  ) );
            else
                return false;
        }
        else
        {
            if( !s.empty() )
            {
                if( s[0] == p[0] || p[0] == '.' )
                    return grep( s.substr(1), p ) || grep( s, p.substr(2) );
                else
                    return grep( s, p.substr(2) );
            }
            else
                return grep( s, p.substr(2) );
        }
    }

    bool isMatch(string s, string p) {
        return grep( s, p );
    }
};

int main()
{
    Solution s;
    string str, p;
    cin >> str >> p;
    cout << ( s.isMatch( str, p ) ? "yes" : "no" ) << endl;

    return 0;
}
