/*---------------leetcode-----------------
---------------Level : Medium-------------
--------------Kth Largest Number----------
----------------storm Han-----------------
----------------2016.08.24----------------

Question describing:
Find the kth largest element in an unsorted array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.

*/

//not complete
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	int L = 0, R = nums.size() - 1;
	while (L < R)
	{
		int left = L, right = R;
		int key = nums[left];

		while (left < right)
		{
			while (left < right && nums[right] < key) --right;
			nums[left] = nums[right];

			while (left < right && nums[left] >= key) ++left;
			nums[right] = nums[left];
		}
	}
}