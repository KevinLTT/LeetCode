#include "u.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.empty() )
            return 0;
        if( nums[0] == nums[nums.size()-1] )
            return 1;

        int valid = 0;
        int max = nums[nums.size()-1], pre = nums[0];
        for( int i = 1; i < nums.size(); i++ )
        {
            if( nums[i] > pre )
            {
                pre = nums[i];
                int temp = nums[i];
                nums[i] = nums[++valid];
                nums[valid] = temp;
                if( nums[valid] == max )
                    break;
            }
        }

        return valid+1;
    }
};
