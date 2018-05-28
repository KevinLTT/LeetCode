#include "u.h"

class Solution {
public:
    //void find( vector<int>& candidates, int target, vector<int>& combine, int index, set<vector<int>>& res )
    void find( vector<int>& candidates, int target, vector<int>& combine, int index, vector<vector<int>>& res )
    {
        if( target <= 0 )
        {
            if( target == 0 )
                res.push_back( combine );
                //res.insert( combine );
            return;
        }

        if( index >= candidates.size() ||  candidates[index] > target )
            return;

        //combine.push_back( candidates[index] );
        //find( candidates, target-candidates[index], combine, index+1, res );
        //combine.pop_back();
        //find( candidates, target, combine, index+1, res );

        for( int i = index; i < candidates.size(); i++ )
        {
            if( candidates[i] > target )
                return;

            if( i && i > index && candidates[i] == candidates[i-1] )
                continue;

            combine.push_back( candidates[i] );
            find( candidates, target-candidates[i], combine, i+1, res );
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //set<vector<int>> res;
        vector<vector<int>> res;
        sort( candidates.begin(), candidates.end() );
        vector<int> combine;
        find( candidates, target, combine, 0, res );
        //vector<vector<int>> res1;
        //for( auto a : res )
            //res1.push_back( a );
        //return res1;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> candidates = { 2, 5, 2, 1, 2 };
    int target = 5;
    auto res = s.combinationSum2( candidates, target );
    for( auto a : res )
    {
        for( auto b : a )
            cout << " " << b;
        cout << endl;
    }
}
