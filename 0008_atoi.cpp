#include "u.h"

#define toInt(x) (x-'0')

class Solution {
public:
    int myAtoi(string str) {
        long long result = 0; 
        int sign = 1;
        if( !str.empty() )
        {
            int i = str.find_first_not_of( ' ' );
            if( str[i] == '+' || str[i] == '-' )
                sign = str[i++] == '+' ? 1 : -1;
            while( i < str.size() && str[i] >= '0' && str[i] <= '9' )
            {
                result = result*10 + toInt(str[i++]);
                if( result*sign >= INT_MAX ) return INT_MAX;
                if( result*sign <= INT_MIN ) return INT_MIN;
            }
            return sign*result;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi( "-123" ) << endl;
}
