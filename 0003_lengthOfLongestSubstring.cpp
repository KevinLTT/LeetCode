#include <string>
using namespace std;

class Solution {
public:
	int findRepeat( char c, string s, int begin, int end)
	{
		begin = begin < 0 ? 0 : begin;
		end = end > s.size() ? s.size() : end;
		for (int i = begin; i < end; i++)
			if (c == s[i])
				return i;

		return -1;
	}

	int findLong(string s, int begin, int nextBegin, int& end )
	{
		for( int i = nextBegin; i < s.size(); i++ )
		{
			int repeatIndex = findRepeat(s[i], s, begin, i);
			if (repeatIndex != -1)
			{
				end = i;
				return repeatIndex + 1;
			}
		}

		end = s.size();
		return s.size();
	}

	int lengthOfLongestSubstring(string s) {
		int longestBegin = 0, longestEnd = 0, begin = 0, end = 0, nextBegin = 0;
		
		while (begin < s.size() )
		{
			//nextBegin = findLong(s, begin, nextBegin, end);
			bool find = false;
			for (int i = nextBegin; i < s.size(); i++)
			{
				//int repeatIndex = findRepeat(s[i], s, begin, i);
				int repeatIndex = -1;
				for (int j = begin; j < i; j++)
					if (s[j] == s[i])
						repeatIndex = j;
				if (repeatIndex != -1)
				{
					end = i;
					nextBegin = repeatIndex + 1;
					find = true;
					break;
				}
			}
			if (!find)
			{
				end = s.size();
				nextBegin = s.size();
			}
			if (end - begin > longestEnd - longestBegin)
			{
				longestBegin = begin;
				longestEnd = end;
			}
			begin = nextBegin;
			nextBegin = end;
		}

		return longestEnd - longestBegin;
	}



};