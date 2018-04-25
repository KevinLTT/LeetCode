#include "u.h"

class Solution {
public:
    string convert( int num, int scale, char x, char y, char z )
    {
        int n = ( num / scale ) % 10;
        if( n <= 3 )
            return string( n, x );
        else if( n == 4 )
            return string( 1, x) + string( 1, y );
        else if( n < 9 )
            return string( 1, y ) + string( n-5, x );
        else 
            return string( 1, x ) + string( 1, z );
    }

    string thousandConvert( int num )
    {
        return convert( num, 1000, 'M', 'A', 'B' );
    }

    string hundredConvert( int num )
    {
        return convert( num, 100, 'C', 'D', 'M' );
    }

    string tenConvert( int num )
    {
        return convert( num, 10, 'X', 'L', 'C' );
    }

    string digitConvert( int num )
    {
        return convert( num, 1, 'I', 'V', 'X' );
    }

    string intToRoman(int num) {
        return thousandConvert( num ) + hundredConvert( num ) + tenConvert( num ) + digitConvert( num );
    }
};

int main()
{
    Solution s;
    int a;
    cin >> a;
    cout << s.intToRoman( a ) << endl;
    return 0;
}
