/*---------------leetcode-----------------
---------------FInd Peak Element----------
----------------storm Han-----------------
----------------2016.03.30----------------

Question describing:
peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
#include <vector>

using namespace std;


int findPeakElement(vector<int>& nums) {
	if (nums.size() == 1) return 0;
	if (nums[0] > nums[1]) return 0;
	if (nums[nums.size() - 1] > nums[nums.size() - 2])
		return nums.size() - 1;

	for (int i = 1; i < nums.size() - 1; ++i)
	{
		if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
			return i;
	}
}

//¶þ·ÖµÝ¹é£¡£¡£¡T(N) = 0(lgn)

int findpeak(vector<int>& nums, int low, int high)
{
	if (low == high) return low;

	int mid = (low + high) / 2;
	if (nums[mid] > nums[mid + 1])
		return findpeak(nums, low, mid);
	else
		return findpeak(nums, mid + 1, high);
}

int findPeakElement1(vector<int>& nums)
{
	findpeak(nums, 0, nums.size() - 1);
}