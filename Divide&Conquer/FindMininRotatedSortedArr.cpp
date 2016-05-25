/*---------------leetcode-----------------
---------------Level : Medium-------------
-----Find Min in Rotated Sorted Array-----
----------------storm Han-----------------
----------------2016.05.25----------------

Question describing:
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/

#include <vector>

using namespace std;

//O(n)的算法 没什么好说的。
int findMin1(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		if (nums[i] > nums[i + 1])
			return nums[i + 1];
	}
	return nums[0];
}

//主要想利用分治法的思想来实现O(logn)的算法
int finda(vector<int>& nums, int left, int right)
{
	if (nums[left] < nums[right] || left == right) return nums[left];

	if (right - left == 1) return (nums[left] < nums[right]) ? nums[left] : nums[right];

	int mid = (left + right) / 2;

	if (nums[mid] < nums[left])
	{
		return finda(nums, left, mid);
	}
	else
	{
		return finda(nums, mid, right);
	}
}

int findMin(vector<int>& nums)
{
	if (nums.size() == 1) return nums[0];

	int ret = finda(nums, 0, nums.size() - 1);

	return ret;
}