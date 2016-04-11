/*---------------leetcode-----------------
---------------Burst Balloon--------------
----------------storm Han-----------------
----------------2016.04.11----------------

Question describing:
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. 
If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
#include <vector>

using namespace std;
//我自己用dfs来做，但超时了，遇到这种求最极值的问题，很多时候可以考虑用动态规划来做。找好递推公式
//int maxCoin = -1;
//
//void dfs(int step, int value, vector<int> operat, int n)
//{
//	if (step == n)
//	{
//		if (value > maxCoin)
//			maxCoin = value;
//	}
//	else
//	{
//		int temp_val;
//		vector<int> vec;
//		int i = 0;
//		while (i < n - step)
//		{
//			temp_val = value;
//			vec = operat;
//			vector<int>::iterator it = vec.begin();
//			if (step == n - 1)
//			{
//				temp_val += *it;
//			}
//			else if (i == 0)
//			{
//				temp_val += (*it) * (*(it + 1));
//			}
//			else if (i == n - step - 1)
//			{
//				temp_val += (*(it + i)) * (*(it + i - 1));
//			}
//			else
//			{
//				temp_val += (*(it + i)) * (*(it + i - 1)) * (*(it + i + 1));
//			}
//			vec.erase(it + i);
//			dfs(step + 1, temp_val, vec, n);
//
//			i++;
//		}
//
//	}
//}
//
//int maxCoins1(vector<int>& nums) {
//	dfs(0, 0, nums, nums.size());
//	return maxCoin;
//}
//
int max11(int a, int b)
{
	if (a > b) return a;
	return b;
}


int maxCoins(vector<int>& nums)
{
	int n = nums.size();
	nums.insert(nums.begin(), 1);
	nums.push_back(1);

	vector<vector<int>>  dp(nums.size(), vector<int>(nums.size(), 0));

	//!!!注意循环的顺序@@@
	//for (int i = 1; i <= n; ++i)
	//{
	//	for (int j = i; j <= n; ++j)
	//	{
	//		for (int k = i; k <= j; ++k)
	//		{
	//			dp[i][j] = max11(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
	//		}
	//	}
	//}
	for (int len = 1; len <= n; ++len) {
		for (int left = 1; left <= n - len + 1; ++left) {
			int right = left + len - 1;
			for (int k = left; k <= right; ++k) {
				dp[left][right] = max11(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
			}
		}
	}

	return dp[1][n];
}