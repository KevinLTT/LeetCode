#include "u.h"

class Solution {
public:
    vector<int> addVec( const vector<int> &a, const vector<int> &b, const vector<int> &wordTimes )
    {
        vector<int> nil;
        if( a.empty() || b.empty() || a.size() != b.size() )
            return nil;

        vector<int> res;
        for( int i = 0; i < a.size(); i++ )
        {
            if( a[i] + b[i] > wordTimes[i] )
                return nil;
            else
                res.push_back( a[i] + b[i] );
        }

        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if( words.empty() || words[0].size()*words.size() > s.size() )
            return res;

        auto wordLength = words[0].size();
        auto wordCount = words.size();

        sort( words.begin(), words.end() );  
        vector<int> wordsTimes;
        int i = -1, pre = -1;
        for( int j = 0; j < words.size(); j++ )
        {
            if( pre < 0 || words[j] != words[ pre ] )
            {
                wordsTimes.push_back( 1 );
                pre = j;
                i++;
            }
            else
                wordsTimes[i]++;
        }
        words.erase( unique( words.begin(), words.end() ), words.end() );

        vector<int> table[s.size()];
        vector<int> match( s.size(), -1 );
        for( int i = 0; i < s.size() - wordLength + 1; i++ )
            for( int j = 0; j < words.size(); j++ )
            {
                if( s.substr( i, wordLength ) == words[j] )
                {
                    match[i] = j;
                    table[i].resize( words.size(), 0 );
                    table[i].at( j )++;
                    break;
                }
            }

        int range = wordLength*2;
        bool fast = false;
        while( range <= wordCount*wordLength )
        {
            for( int i = 0; i < s.size() - range + 1; i += 1  )
            {
                if( fast )
                    table[i] = addVec( table[i], table[i+range/2], wordsTimes );
                else if( table[i].size() == wordsTimes.size() )
                {
                    int matchIndex = match[ i + range - wordLength ];
                    if( matchIndex == -1 )
                        table[i].clear();
                    else
                    {
                        table[i].at( matchIndex )++;
                        if( table[i].at( matchIndex ) > wordsTimes[matchIndex] )
                            table[i].clear();
                    }
                }
            }

            if( range*2 <= wordCount*wordLength )
            {
                fast = true;
                range *= 2;
            }
            else
            {
                fast = false;
                range += wordLength;
            }
        }
        
        for( int i = 0; i < s.size()-wordCount*wordLength+1; i++ )
        {
            auto tempTable = table[i];
            if( tempTable.empty() )
                continue;

            bool meet = true;
            for( int j = 0; j < tempTable.size(); j++ )
                if( tempTable[j] != wordsTimes[j] )
                {
                    meet = false;
                    break;
                }
            if( meet )
                res.push_back( i );
        }

        return res;
    }
};

int main()
{
    string str = "barfoothefoobarman";
    vector<string> words = { "foo", "bar" };
    Solution s;
    auto res = s.findSubstring( str, words );

    return 0;
}
