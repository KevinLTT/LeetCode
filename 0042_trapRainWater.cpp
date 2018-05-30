#include "u.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int volumn = 0;
        
        vector<int> trapHeight( height.size(), 0 );
        int left = 0, right = 0;
        while( right < height.size() )
        {
            if( right-left > 1 )
            {
                int trap = height[left] < height[right] ? height[left] : height[right];
                for( int mid = left+1; mid < right; mid++ )
                    volumn += trap-height[mid];
            }
            left = right;
            right = right+1;
            while( right == 0 )
                right++;
            for( int i = right+1; i < height.size() && height[right] < height[left]; i++ )
            {
                if( height[i] > height[right] )
                {
                    right = i;
                }
            }
        };

        return volumn;
    }

};

int main() 
{
    Solution s;
    //vector<int>
}
