#pragma once
#include "u.h"

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		auto numsCopy = nums;
		sort(numsCopy.begin(), numsCopy.end());
		int small = 0, large = numsCopy.size() - 1;
		while (small != large)
		{
			if (numsCopy[small] + numsCopy[large] < target)
				small++;
			else if (numsCopy[small] + numsCopy[large] > target)
				large--;
			else
				break;
		}
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == numsCopy[small] || nums[i] == numsCopy[large])
			{
				result.push_back(i);
				if (result.size() == 2)
					break;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 7, 11, 15 };
	int target = 9;
	auto result = s.twoSum( v, target );
	for( auto n : result )
		cout << n << " " << endl;

	return 0;
}