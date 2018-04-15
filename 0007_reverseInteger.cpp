#include "u.h"
		   
class Solution {
public:

	int reverse(int x) {
        bool nonnegative = x < 0 ? false : true;
        x = abs( x );

        stringstream ss;
        ss << x;
        string num = ss.str();
        for( int i = 0; i < num.size()/2; i++ )
        {
            char temp = num[i];
            num[i] = num[num.size()-i-1];
            num[num.size()-i-1] = temp;
        }

        string maxPos = "2147483647";
        string maxNeg = "2147483648";


        int result;
        if( num.size() < maxPos.size() )
            result = ( nonnegative ? 1 : -1 ) * atoi( num.c_str() );
        else if( nonnegative )
            result = ( num > maxPos ) ? 0 : atoi(num.c_str());
        else
            result = ( num > maxNeg ) ? 0 : -1 * atoi(num.c_str());

		return result;
	}
};

int main()
{
	Solution s;
    int a = -2147483412;
	cout << s.reverse(a) << endl;
}
