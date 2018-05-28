#include "u.h"

class Solution {
public:
    vector<vector<int>> find( vector<int>& candidates, int target, int beginIndex, vector<int> preCombination )
    {
        vector<vector<int>> reses;
        int num = candidates[beginIndex];
        if( beginIndex >= candidates.size() || num > target )
            return reses;

        for( int repeat = 0; target - num*repeat >= 0; repeat++ )
        {
            auto combine = preCombination;
            for( int i = 0; i < repeat; i++ )
                combine.push_back( num );
            
            if( target - num*repeat == 0 )
                reses.push_back( combine );
            else
            {
                auto postCombineReses = find( candidates, target-num*repeat, beginIndex+1, combine );
                if( !postCombineReses.empty() )
                {
                    for( auto postRes : postCombineReses )
                    {
                        //vector<int> res;
                        //res.insert( res.end(), combine.begin(), combine.end() );
                        //res.insert( res.end(), postRes.begin(), postRes.end() );
                        reses.push_back( postRes );
                    }
                }
            }
        }

        return reses;
    }

    vector<vector<int>> findCombination( vector<int> candidates, int target ) 
    {
        sort( candidates.begin(), candidates.end() );
        int beginIndex = 0;
        vector<int> preCombination;
        return find( candidates, target, beginIndex, preCombination );
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans = findCombination( candidates, target );    
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> candidates = { 2, 3, 5 };
    int target = 8;
    auto res = s.combinationSum( candidates, target );
    for( auto item : res )
    {
        for( auto a : item )
            cout << " " << a;
        cout << endl;
    }

    return 0;
}


