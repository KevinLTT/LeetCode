#include "u.h"

class Solution{
public:
    string simpleMul( string num, char digit, int scale = 0 )
    {
        int carry = 0, i = num.size()-1;
        string result = "";
        int intDigit = digit - '0';
        while( i >= 0 || carry > 0 )
        {
            int numDigit = i >= 0 ? num[i] - '0' : 0;
            int tempProduct = numDigit * intDigit + carry;
            //cout << numDigit << " * " << intDigit << " + " << carry << " = " << tempProduct << endl;
            int resDigit = tempProduct % 10;
            result.insert( result.begin(), 1, '0' + resDigit );
            carry = tempProduct / 10;
            //cout << "resDigit: " << resDigit << " carry: " << carry << endl;
            i--;
            //cout << "result" << i << ": " << result << endl;
        }
        //cout << "result size: " << result.size() << endl;
        //cout << result << endl;

        int beginIndex = 0;
        for( int i = 0; i < result.size()-1; i++ )
        {
            if( result[i] == '0'  )
                beginIndex++;
            else
                break;
        }
        result = result.substr( beginIndex, result.size()-beginIndex );

        if( result.size() > 1 || ( result.size() == 1 && result[0] != '0' ) )
            while( scale > 0 )
            {
                result.append( 1, '0' );
                scale--;
                //cout << "insert" << endl;
            }
        //cout << "after insert size: " << result.size() << endl;

        return result;       
    }

    string strAdd( string num1, string num2 )
    {
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        string result = "";
        int digit = num1[0]-'0';
        while( i >= 0 || j >= 0 || carry > 0 )
        {
            int digitI = i >= 0 ? num1[i--] - '0' : 0;
            int digitJ = j >= 0 ? num2[j--] - '0' : 0;
            int sum = digitI + digitJ + carry;
            int resDigit = sum % 10;
            result.insert( result.begin(), 1, '0' + resDigit );
            carry = sum / 10;
        }
        return result;
    }

    string multiply( string num1, string num2 )
    {
        if( num1.empty() || num2.empty() )
            return string();

        vector<string> interRes;
        for( int i = num1.size()-1; i >= 0; i-- )
        {
            int scale = num1.size()-1-i;
            auto product = simpleMul( num2, num1[i], scale );
            //cout << num1[i] << " mul " << num2 << " = " << product << endl;
            //cout << product.size() << endl;
            //cout << product << endl;
            interRes.push_back( product );
        }

        while( interRes.size() > 1 )
        {
            auto tempNum1 = interRes[interRes.size()-1];
            auto tempNum2 = interRes[interRes.size()-2];
            interRes.pop_back();
            interRes.pop_back();
            interRes.push_back( strAdd(tempNum1, tempNum2 ) );
        };

        return interRes[0];
    }
    
};

int main( int argc, char** argv )
{
    Solution s;
    //string num1( argv[1] );
    //string num2( argv[2] );
    //cout << s.multiply( num1, num2 ) << endl;
}
