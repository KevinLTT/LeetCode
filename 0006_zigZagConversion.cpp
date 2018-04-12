#pragma once
#include "u.h"
class Solution {
public:
	string Convert(string s, int numRows) {
		if (numRows <= 1)
			return s;

		vector<int> row(s.size());
		int rowNum = 1;
		bool positive = true;
		for (int i = 0; i < s.size(); i++)
		{
			row[i] = rowNum;
			rowNum = positive ? rowNum + 1 : rowNum - 1;
			positive = positive ? (rowNum == numRows ? false : true) : (rowNum == 1 ? true : false);
		}

		vector<string> results(numRows);
		for (auto i = 0; i < s.size(); i++)
			results[row[i]-1].append(1, s[i]);

		string result;
		for (auto itr = results.begin(); itr != results.end(); itr++)
			result.append(*itr);

		return result;
	}
};