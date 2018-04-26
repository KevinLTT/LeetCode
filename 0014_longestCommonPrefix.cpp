#include "u.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.empty() )
            return "";
        if( strs.size() == 1 )
            return strs[0];

        string prefix = "";
        for( int i = 0; i < strs[0].size(); i++ )
        {
            bool same = true;
            for( int j = 1; j < strs.size(); j++  )
            {
                if( strs[j][i] != strs[0][i] )
                {
                    same = false;
                    break;
                }
            }
            if( same )
                prefix.append( 1, strs[0][i] );
            else
                break;
        }
        return prefix;
    }
};
