#include "u.h"

class Solution {
public:
    map< char, vector<char> > dict;
    Solution()
    {
        vector<char> c2 = { 'a', 'b', 'c' };
        vector<char> c3 = {'d', 'e', 'f' };
        vector<char> c4 = {'g', 'h', 'i' };
        vector<char> c5 = {'j', 'k', 'l' };
        vector<char> c6 = {'m', 'n', 'o' };
        vector<char> c7 = {'p', 'q', 'r', 's' };
        vector<char> c8 = {'t', 'u', 'v' };
        vector<char> c9 = {'w', 'x', 'y', 'z' };
        dict['2'] = c2;
        dict['3'] = c3;
        dict['4'] = c4;
        dict['5'] = c5;
        dict['6'] = c6;
        dict['7'] = c7;
        dict['8'] = c8;
        dict['9'] = c9;
    }


    vector<string> combine( vector<string> preCombine, char c )
    {
        if( dict.count( c ) <= 0 )
            return preCombine;

        auto chars = dict[c];
        vector<string> res;
        
        if( preCombine.empty() )
            for( int i = 0; i < chars.size(); i++ )
                res.push_back( string( 1, chars[i] ) );
        else
        {
            for( int i = 0; i < preCombine.size(); i++ )
                for( int j = 0; j < chars.size(); j++  )
                    res.push_back( preCombine[i] + string( 1, chars[j] ) );
        }

        return res;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for( int i = 0; i < digits.size(); i++ )
            res = combine( res, digits[i] );

        return res;
    }
};

int main()
{
    Solution s;
    string nums = "23";
    s.letterCombinations( nums );

    return 0;
}
