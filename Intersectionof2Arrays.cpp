/*---------------leetcode-----------------
---------------Level : Easy---------------
-------Intersection of two Arrays---------
----------------storm Han-----------------
----------------2016.06.04----------------

Question describing:
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ret;
	if (nums1.size() * nums2.size() == 0) return ret;

	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int len1 = nums1.size();
	int len2 = nums2.size();
	if (nums1[0] > nums2[len2 - 1] || nums2[0] > nums1[len1 - 1]) return ret;

	int i = 0, j = 0;
	int cur = 0xffffff;
	while (i < len1 && j < len2)
	{
		if (nums1[i] == nums2[j])
		{
			if (cur != nums1[i])
			{
				ret.push_back(nums1[i]);
				cur = nums1[i];
				++i; ++j;
				continue;
			}
			else
			{
				i++; j++;
				continue;
			}
		}
		if (nums1[i] < nums2[j])
		{
			++i;
			continue;
		}
		if (nums1[i] > nums2[j])
		{
			j++;
			continue;
		}
	}
	return ret;
}