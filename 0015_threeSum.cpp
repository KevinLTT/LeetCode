#include "u.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if( nums.size() < 3 )
            return result;
        sort( nums.begin(), nums.end() );

        for( int i = 0; i < nums.size()-2; i++ )
        {
            int target = -1 * nums[i];
            int front = i+1, back =nums.size()-1;
            while( front < back )
            {
                if( nums[front]+nums[back] < target )
                    front++;
                else if( nums[front]+nums[back] > target )
                    back--;
                else
                {
                    vector<int> triplet( 3, 0 );
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    result.push_back( triplet );

                    while( front < back && nums[front] == triplet[1] ) front++;
                    while( front < back && nums[back] == triplet[2] ) back--;
                }
            }
            
            while( i+1 < nums.size() && nums[i] == nums[i+1] )
                i++;
        }
        
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> input = { -1, 0, 1, 2, -1, -4 };
    auto result = s.threeSum( input );


    return 0;
}
