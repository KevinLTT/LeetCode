#include "u.h"

class Solution {
public:
    void swap( int &a, int &b )
    {
        int temp = b;
        b = a;
        a = temp;
    }
     
    void mySort( vector<int> &nums, int begin, int end )
    {
        if( end - begin < 10 )
        {
            for( int i = begin; i < end-1; i++ )
            {
                int min = i;
                for( int j = i+1; j < end; j++ )
                {
                    if( nums[j] < nums[min] )
                        min = j;
                }
                swap( nums[i], nums[min] );
            }
        }
        else
        {
            int mid = (end-begin) / 2;
            int pivot = ( nums[begin] > nums[mid] ) ? 
                            ( nums[begin] > nums[end-1] ? ( nums[mid] > nums[end-1] ? mid : end-1 ) : begin ):
                            ( nums[mid] > nums[end-1] ? ( nums[begin] > nums[end-1] ? begin : end-1 ) : mid );
            swap( nums[pivot], nums[end-1] );  
            int i = begin, j = end-2;
            while( i < j )
            {
                while( nums[i] < nums[end-1] && i < end-2 ) i++;
                while( nums[j] > nums[end-1] && j > begin) j--;
                if( i > j ) 
                    break;

                swap( nums[i], nums[j] );
            };
            swap( nums[i], nums[end-1] );
            mySort( nums, begin, i  );
            mySort( nums, i+1, end );
        }

    }

    void exchange( vector<int> &nums, int begin )
    {
        int exchange1 = -1, exchange2 = -1;
        int min = begin;

        for( int i = begin+1; i < nums.size(); i++ )
        {
            if( nums[i] <= nums[min] )
            {
                min = i;
                if( exchange1 != -1 && nums[i] <= nums[exchange2] && nums[i] > nums[exchange1])
                    exchange2 = i;
            }
            else if( nums[i] > nums[ min ] )
            {
                exchange1 = min;
                exchange2 = i;
                min = i;
            }
        }
        swap( nums[exchange1], nums[exchange2] );

        mySort( nums, exchange1+1, nums.size() );
    }

    void nextPermutation(vector<int>& nums) {
        exchange( nums, 0 );
    }
};

int main()
{
    Solution s;
    vector<int> v;
    for( int i = 0; i < 100; i++ )
        v.push_back( 100 - i );
    s.mySort( v, 0, v.size() );
    for( auto n : v )
        cout << n << " ";
    cout << endl;
    return 0;
}
