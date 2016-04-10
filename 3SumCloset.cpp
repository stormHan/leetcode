/*---------------leetcode-----------------
---------------Level : Medium-------------
----------------3 Sum Closet--------------
----------------storm Han-----------------
----------------2016.04.10----------------

Question describing:
Given an array S of n integers, find three integers in S such that

the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

#include <algorithm>
#include <vector>

using namespace std;

int compare(int a, int b, int target)
{
	/*vector<int> temp;
	temp.push_back(fabs((float)a - target));
	temp.push_back(fabs((float)b - target));
	temp.push_back(fabs((float)c - target));
	temp.push_back(fabs((float)d - target));

	sort(temp.begin(), temp.end());
	if (temp[0] == (int)fabs((float)a - target)) return a;
	if (temp[0] == (int)fabs((float)b - target)) return b;
	if (temp[0] == (int)fabs((float)c - target)) return c;
	if (temp[0] == (int)fabs((float)d - target)) return d;*/

	if (fabs((float)a - target) <= fabs((float)b - target))return a;
	else
	{
		return b;
	}
}

int threeSumClosest(vector<int>& nums, int target) {
	int sum;
	int intern;
	int n1, n2, n3;
	int pre_sum;
	sort(nums.begin(), nums.end());


	for (int i = 2; i < nums.size(); i++)
	{
		n1 = nums[i - 2];
		n2 = nums[i - 1];
		n3 = nums[i];
		sum = n1 + n2 + n3;
		if (sum < target)
		{
			pre_sum = sum;
			intern = target - sum;
			continue;
		}
		else if (i == 2)
		{
			return sum;
		}
		else {
			int p = 0;
			int q = i - 1;
			int ret = 0xffffff;
			while (p < q){
				sum = nums[p] + nums[q] + nums[i];
				if (abs(sum - target) < abs(ret - target))
					ret = sum;

				if (sum > target)
					q--;
				if (sum < target)
					p++;

				if (ret == target)
					return ret;
			}

			return compare(ret, pre_sum, target);

		}

	}
	return sum;
}
