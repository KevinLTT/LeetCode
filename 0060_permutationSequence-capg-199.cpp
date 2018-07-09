#include "u.h"

class Solution {
public:
    int factorial[10];

    Solution()
    {
        factorial[0] = 1;
        for( int i = 1; i <= 9; i++ )
            factorial[i] = i * factorial[i-1];
    }

    char getNextNum(vector<int>& remaining, int& k)
    {
        int n = remaining.size();
        auto itr = remaining.begin();
        while(k > factorial[n-1])
        {
            itr++;
            k -= factorial[n-1];
        }

        auto nextNum = *itr;
        remaining.erase(itr);
        return (char)(nextNum + '0');
    }

    string getPermutation(int n, int k) {
        vector<int> remaining;
        for(int i = 1; i <= n; i++)
            remaining.push_back(i);

        string res = "";
        while(not remaining.empty())
            res.push_back(getNextNum(remaining, k));
            
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(4, 1) << endl;
}
