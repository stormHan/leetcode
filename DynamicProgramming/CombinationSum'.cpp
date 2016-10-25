/*---------------leetcode-----------------
---------------Level : Medium-------------
------------ Combiantion Sum IV-----------
----------------storm Han-----------------
----------------2016.10.25----------------
Question describing:
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
*/

#include "main.h"

int combinationSum4(vector<int>& nums, int target) {
	if (nums.size() == 0) return 0;
	vector<int> dp(target + 1, 0);

	int nb = nums.size();
	sort(nums.begin(), nums.end());
	dp[0] = 0;
	for (int i = 1; i <= target; ++i)
	{
		if (i < nums[0])
		{
			dp[i] = 0;
			continue;
		}
		for (int j = 0; nums[j] <= i && j < nb; ++j)
		{
			dp[i] += dp[i - nums[j]];
			if (nums[j] == i)
				dp[i]++;
		}
	}

	return dp[target];
}