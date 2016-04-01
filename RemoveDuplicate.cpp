/*---------------leetcode-----------------
----------------Rotate Image--------------
----------------storm Han-----------------
----------------2016.03.21----------------

Question describing:
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question

*/

#include <vector>
using namespace std;



int removeDuplicates1(vector<int>& nums) {
	int length = nums.size();
	if (length == 0) return length;
	int count = 0;
	for (int i = 0; i < length; i++)
	{

		if (i == length - 1)
		{
			nums[count] = nums[i];
			count++;
			break;
		}
		while (nums[i] == nums[i + 1])
		{
			i++;
			if (i == length - 1) break;
		}
		nums[count] = nums[i];
		count++;
	}



	return count;
}