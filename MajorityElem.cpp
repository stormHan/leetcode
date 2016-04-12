/*---------------leetcode-----------------
----------------Majority Element----------
----------------storm Han-----------------
----------------2016.03.2----------------

Question describing:
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums) {
	int maxcount = 0;
	map<int, int> hmap;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (!hmap.count(nums[i]))
		{
			hmap.insert(pair<int, int>(nums[i], 1));
		}
		else
		{
			hmap[nums[i]]++;
		}

		if (hmap[nums[i]] > maxcount) maxcount = hmap[nums[i]];
		if (maxcount > nums.size() / 2) return nums[i];
	}
}

vector<int> majorityElement2(vector<int>& nums) {
	map<int, int> hmap;
	int me1 = 0, me2 = 0;
	int c1 = 0, c2 = 0;
	vector<int> ret;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (!hmap.count(nums[i]))
		{
			hmap.insert(pair<int, int>(nums[i], 1));
		}
		else
		{
			hmap[nums[i]]++;
		}
		if (nums[i] != me1 && nums[i] != me2)
		{
			if (hmap[nums[i]] > c1) {
				me1 = nums[i]; c1 = hmap[nums[i]];
			}
			else if (hmap[nums[i]] > c2) {
				me2 = nums[i]; c2 = hmap[nums[i]];
			}
		}
		else if (nums[i] == me1)
		{
			c1++;
		}
		else
		{
			c2++;
		}
	}

	if (c1 > nums.size() / 3) ret.push_back(me1);
	if (c2 > nums.size() / 3) ret.push_back(me2);
	return ret;
}