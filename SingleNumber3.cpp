/*---------------leetcode-----------------
---------------Level : Medium-------------
---------------Single Number III ---------
----------------storm Han-----------------
----------------2016.05.21----------------

Question describing:
Given an array of numbers nums, in which exactly two elements appear only once
and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
*/

#include <vector>
#include <map>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
	map<int, int>hmap;
	vector<int> ret;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (hmap.count(nums[i]) == 0)
		{
			hmap.insert(pair<int, int>(nums[i], 1));
		}
		else if (hmap[nums[i]] == 1)
		{
			hmap[nums[i]] = 0;
		}
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (hmap[nums[i]] == 1)
		{
			ret.push_back(nums[i]);
		}
	}

	return ret;
}