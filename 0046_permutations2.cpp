class Solution {
public:
    void perm( vector<vector<int>>& res, vector<int>& nums, int begin, vector<int>& combination )
    {
        if( combination.size() >= nums.size() )
        {
            res.push_back(combination);
            return;
        }
        
        map<int, int> used;
        for( int i = begin; i < nums.size(); i++ )
        {
            if( used[nums[i]] > 0 )
                continue;

            used[nums[i]] = 1;
            swap( nums[begin], nums[i] );
            combination.push_back( nums[begin] );
            perm( res, nums, begin+1, combination );
            swap( nums[begin], nums[i] );
            combination.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if( nums.empty() )
            return res;
        vector<int> combination;
        perm( res, nums, 0, combination );
        return res;
        
    }
};
