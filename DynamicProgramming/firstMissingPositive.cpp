#include "main.h"

int firstMissingPositive(vector<int>& nums) {
	vector<int> dp(nums.size() + 1, 0);
	unordered_set<int> a;

	dp[0] = 1;

	for (int i = 0; i < nums.size(); ++i)
	{
		a.insert(nums[i]);

		if (dp[i] != nums[i])
			dp[i + 1] = dp[i];
		else{
			dp[i + 1] = dp[i] + 1;
			while (a.find(dp[i + 1]) != a.end())
			{
				dp[i + 1]++;
			}
		}
	}
	return dp[nums.size()];
}
