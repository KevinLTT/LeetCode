#include "u.h"
 
struct wordMap
{
    string originalWord;
    string sortedWord;
    wordMap( string word ): originalWord(word)
    {
        sort(word.begin(), word.end());
        sortedWord = word;
    }

};

bool compare( const wordMap& a, const wordMap& b )
{
    return a.sortedWord < b.sortedWord;        
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<wordMap> list;
        for( auto word : strs )
            list.push_back( wordMap(word) );

        sort( list.begin(), list.end(), compare );
        
        vector<vector<string>> res;
        string pre = "";
        vector<string> anagrams;
        for( auto wordMap : list )
        {
            if( wordMap.sortedWord == pre )
                anagrams.push_back( wordMap.originalWord );
            else
            {
                if( !anagrams.empty() )
                    res.push_back(anagrams);
                pre = wordMap.sortedWord;
                anagrams.resize(0);
                anagrams.push_back(wordMap.originalWord);
            }
        }
        if( !anagrams.empty() )
            res.push_back(anagrams);
        
        return res;
    }
};
