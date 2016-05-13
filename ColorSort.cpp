/*---------------leetcode-----------------
----------------Color Sort----------------
----------------storm Han-----------------
----------------2016.05.09----------------

Question describing:

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
	int count0 = 0, count1 = 0, count2 = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		switch (nums[i])
		{
		case 0:count0++; break;
		case 1:count1++; break;
		case 2:count2++; break;

		default:
			break;
		}
	}

	int step = 0;
	while (count0 > 0)
	{
		nums[step] = 0;
		count0--;
		step++;
	}
	while (count1 > 0)
	{
		nums[step] = 1;
		count1--;
		step++;
	}
	while (count2 > 0)
	{
		nums[step] = 2;
		count2--;
		step++;
	}
}