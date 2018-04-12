#pragma once
#include "u.h"

typedef struct SubString
{
	int begin, end;
	int length;
	SubString(int Begin, int End) : begin(Begin), end(End) { length = end - begin; }
}subs;

class Solution {
public:
	bool isPalindrome(string s, int begin = 0, int end = -1)
	{
		end = (end == -1) ? s.size() : end;
		for (int i = 0; i < (end - begin - 1) / 2; i++)
			if (s[begin + i] != s[end - i - 1])
				return false;
		return true;
	}

	vector<subs> findCandidates(string s, int offset)
	{
		vector<subs> candidates;
		for (int i = 0; i + offset <= s.size(); i++)
			if (isPalindrome(s, i, i + offset))
				candidates.push_back(subs(i, i + offset));
		return candidates;
	}

	string longestPalindrome(string s) {
		if (isPalindrome(s))
			return s;

		vector<subs> candidates;
		int big = s.size(), small = 0;
		while ( big - small > 0)
		{
			int offset = (big + small) / 2;
			auto tempCandidates = findCandidates(s, offset);
			if (tempCandidates.empty())
				big = (big + small) / 2;
			else
			{
				candidates = tempCandidates;
				small = (big + small) / 2;
			}
		}

		if (candidates.empty())
			return "";
		else
			return s.substr(candidates[0].begin, candidates[0].end);
	}
};