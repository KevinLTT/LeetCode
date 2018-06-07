#include "u.h"

class Solution {
public:
    bool match( const string& s, const string& p, unsigned int indexS, unsigned int indexP  )
    {
        if( indexP >= p.size()  )
        {
            if( indexS >= s.size() )
                return true;
            else
                return false;
        }

        if( indexS >= s.size() )
        {
            for( unsigned int i = indexP; i < p.size(); i++ )
                if( p[i] != '*' )
                    return false;

            return true;
        }

        if( p[indexP] == '?' || p[indexP] == s[indexS] )
            return match( s, p, indexS+1, indexP+1  );
        else if( p[indexP] == '*' )
        {
            if( indexP + 1 < p.size() and p[indexP+1] == '*'  )
                return match( s, p, indexS, indexP+1 );
            else
            {
                for( int i = 0; i < s.size()-indexS; i++ )
                {
                    
                }
            }
        }
        else
            return false;
    }

    bool isMatch(string s, string p)  {
        return match( s, p, 0, 0 );
    }
};

int main()
{
    Solution s;
    string s1( "aba" );
    string p( "a*" );
    cout << s.isMatch( s1, p ) << endl;
}
