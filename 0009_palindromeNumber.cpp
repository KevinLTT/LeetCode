class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;
    
        long num = x;
        long reverse = 0;
        while( x > 0 )
        {
            reverse = reverse*10 + x%10;
            x /= 10;
        }
        return num == reverse;
    }
};
