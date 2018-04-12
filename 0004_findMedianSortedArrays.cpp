#pragma once
#include <vector>
#include <algorithm>
using namespace std;

#define getMedian(x)  (x.size()%2==0) ? (x[x.size() / 2] + x[x.size() / 2 - 1]) / 2.0f : x[x.size()/2]  
#define bigcut(x) (x.size() >= 4) ? ( (x.size()%2==0) ? vector<int>( x.begin(), x.begin()+ x.size()/2 + 1 ) : vector<int>( x.begin(), x.begin()+x.size()/2+2) ) : x
#define smallcut(x) (x.size() >= 4) ? ( (x.size()%2==0) ? vector<int>( x.begin()+ x.size()/2 - 1, x.end() ) : vector<int>( x.begin()+x.size()/2-1, x.end() ) ) : x

class Solution {
public:
	void cut(vector<int> &ns, int cutNum, int type = 0)
	{
		if (ns.size() < 4)
			return;

		//small cut
		if (type == 0)
			ns = vector<int>(ns.begin() + cutNum, ns.end());
		//big cut
		else
			ns = vector<int>(ns.begin(), ns.end() - cutNum);
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		while (nums1.size() >= 4 && nums2.size() >= 4)
		{
			double median1 = getMedian(nums1), median2 = getMedian(nums2);
			int cutNum1 = nums1.size() / 2 - 1, cutNum2 = nums2.size() / 2 - 1, cutNum = (cutNum1 < cutNum2) ? cutNum1 : cutNum2;
			if (median1 > median2)
			{
				cut(nums1, cutNum, 1);
				cut(nums2, cutNum, 0);
			}
			else
			{
				cut(nums1, cutNum, 0);
				cut(nums2, cutNum, 1);
			}
		}

		int i=0, j=0;
		vector<int> result;
		while (i < nums1.size() || j < nums2.size())
		{
			if (i == nums1.size())
				while (j < nums2.size())
					result.push_back(nums2[j++]);
			else if (j == nums2.size())
				while (i < nums1.size())
					result.push_back(nums1[i++]);
			else
				result.push_back((nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++]);
		}

		return getMedian(result);
		if (result.size() % 2 == 0)
			return (result[result.size() / 2] + result[result.size() / 2 - 1]) / 2.0f;
		else
			return result[result.size() / 2];
	}
};