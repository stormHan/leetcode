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