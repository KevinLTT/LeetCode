#define USED 0x0fffffff

class Solution {
public:
    void perm( vector<vector<int>>& res, vector<int>& nums, vector<int>& combination )
    {
        if( combination.size() == nums.size() )
        {
            res.push_back(combination);
            return;
        }

        for( auto &a : nums )
        {
            if( a != USED )
            {
                int temp = a;
                combination.push_back( a );
                a = USED;
                perm( res, nums, combination );
                a = temp;
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if( nums.empty())
            return res;
        vector<int> combination;
        perm( res, nums, combination );
        return res;
    }
};
