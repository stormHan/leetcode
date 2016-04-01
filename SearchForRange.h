/*---------------leetcode-----------------
---------------Level : Medium-------------
-------------Search for Range-------------
----------------storm Han-----------------
----------------2016.03.19----------------

Question describing:
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> index = { -1, 1 };
	bool is_fisrt = true;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
		{
			if (is_fisrt)
			{
				index[0] = i;
				index[1] = i;

				is_fisrt = false;
			}
			else
			{
				index[1] = i;
			}
		}
	}

	return index;
}