#include "u.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto itr = nums.begin();
        while( itr != nums.end() )
        {
            if( *itr <= 0 )
                itr = nums.erase( itr );
            else
                itr++;
        }

        auto N = nums.size();
        for( int i = 0; i < N; i++ )
        {
            int num = abs(nums[i]);
            if( num <= N && nums[num-1] > 0 )
                nums[num-1] = -1 * nums[num-1];
        }

        int miss = 1;
        while( miss <= nums.size() && nums[miss-1] < 0 )
            miss++;

        return miss;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3, 4, -1, 1 };
    cout << s.firstMissingPositive( nums ) << endl;
}
