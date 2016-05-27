/*---------------leetcode-----------------
---------------Level : Medium-------------
-----Remove Duplicates from Sorted Array--
----------------storm Han-----------------
----------------2016.05.25----------------

Question describing:
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements
of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave 
beyond the new length.
*/
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	int tmp = nums[0];
	int count = 0;
	vector<int>::iterator iter = nums.begin();
	for (int i = 0; i < nums.size(); ++i)
	{
		if (tmp != nums[i])
		{
			++iter;
			tmp = nums[i];
			count = 1;
			continue;
		}
		if (count == 1 || count == 0)
		{
			count++;
			++iter;
			continue;
		}
		if (count == 2)
		{
			iter = nums.erase(iter);
			i--;
		}
	}
	return nums.size();
}