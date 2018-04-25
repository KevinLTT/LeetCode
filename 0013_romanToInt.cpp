#include "u.h"

class Solution {
public:
    map< char, int > roman = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        while( i < s.size() )
        {
            if( i+1 < s.size() && roman[s[i+1]] > roman[s[i]] )
            { 
                result += roman[s[i+1]] - roman[s[i]];
                i += 2;
            }            
            else
                result += roman[s[i++]];
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt( "MCMXCIV" ) << endl;
    return 0;
}
