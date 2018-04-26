#include "u.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end() );
        int minDiff = INT_MAX;
        for( int i = 0; i < nums.size() - 2; i++ )
        {
            int t = target - nums[i];
            int front = i+1, back = nums.size()-1;
            while( front < back )
            {
                int sum = nums[front] + nums[back];
                int diff = t - sum;
                if( abs(diff) < abs( minDiff ) )
                    minDiff = diff;

                if( sum < t )
                    front++;
                else if( sum > t )
                    back--;
                else
                    return target;
            }

            while( i+1 < nums.size() && nums[i] == nums[i+1] )
                i++;
        }

        return target-minDiff;
    }
};

int main()
{
    Solution s;
    vector<int> input = { 0, 2, 1, -3 };
    cout << s.threeSumClosest( input, 1 ) << endl;
    return 0;
}
