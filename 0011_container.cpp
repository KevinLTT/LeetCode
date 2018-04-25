#include "u.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        if( height.size() < 2 )
            return 0;

        int head = 0, tail = height.size()-1;
        int maxarea = 0;
        while( head < tail )
        {
            int area = ( tail - head ) * min( height[ head ], height[ tail ] );
            maxarea = ( area > maxarea ) ? area : maxarea;
            if( height[head] < height[tail] )
                head++;
            else
                tail--;
        }

        return maxarea;
    }
};

int main()
{
    return 0;
}
