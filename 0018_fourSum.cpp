#include "u.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if( nums.size() < 4 )
            return res;
        sort( nums.begin(), nums.end() );

        for( int i = 0; i < nums.size() - 3; i++ )
        {
            int t1 = target - nums[i];
            for( int  j = i+1; j < nums.size() - 2; j++ )
            {
                int t2 = t1 - nums[j];
                int front = j+1, back = nums.size()-1;
                while( front < back )
                {
                    int sum = nums[front] + nums[back];
                    if( sum < t2 )
                        front++;
                    else if( sum > t2 )
                        back--;
                    else
                    {
                        vector<int> quadruplets( 4, 0 );
                        quadruplets[0] = nums[i];
                        quadruplets[1] = nums[j];
                        quadruplets[2] = nums[front];
                        quadruplets[3] = nums[back];
                        res.push_back( quadruplets );

                        while( front < back && nums[front] == quadruplets[2] ) front++;
                        while( front < back && nums[back] == quadruplets[3] ) back--;
                    }
                }

                while( j+1 < nums.size() && nums[j] == nums[j+1] ) j++;
            }

            while( i+1 < nums.size() && nums[i] == nums[i+1] ) i++;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1, 0, -1, 0, -2, 2 };
    int target = 0;
    s.fourSum( nums, target );

    return 0;
}
