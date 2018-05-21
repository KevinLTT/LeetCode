#include "u.h"

class Solution
{
public:
    int numVal( vector<int> &nums, int pivot, int i )
    {
        int index = i + pivot;
        index = ( index >= nums.size() ) ? index - nums.size() : index;
        return nums[index];
    }

    int search( vector<int> &nums, int target )
    {
        if( nums.empty() )
            return -1;

        int pivot = 0;
        if( nums[0] > nums[nums.size()-1] )
        { 
            int left = 0, right = nums.size()-1;
            while( left <= right )
            {
                pivot = ( left + right ) / 2;
                if( ( pivot - 1 < 0 || nums[pivot-1] > nums[pivot]  ) && ( pivot + 1 >= nums.size() || nums[pivot] < nums[pivot+1] ) )
                    break;
                else
                {
                    if( nums[pivot] >= nums[0] )
                        left = pivot+1;
                    else
                        right = pivot-1;
                }

            };
        }

        int left = 0, right = nums.size()-1;
        while( left <= right )
        {
            int mid = (left+right)/2;
            cout << "mid: " << mid << endl;
            int num = numVal( nums, pivot, mid );
            cout << num << endl;
            if( num > target )
                right = mid - 1;
            else if( num < target )
                left = mid + 1;
            else
                return mid+pivot;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 4, 5, 6, 7, 0 , 1, 2 };
    cout << s.search( nums, 3 ) << endl;

    return 0;
}
