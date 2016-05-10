/*---------------leetcode-----------------
-----------Min Size Subarray Length-------
----------------storm Han-----------------
----------------2016.05.10----------------

Question describing:
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

*/
#include <vector>

using namespace std;

//我的方法,DP
int minSubArrayLen(int s, vector<int>& nums) {
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	if (sum < s) return 0;

	vector<int> dp(nums.size() + 1, 0);

	dp[0] = nums.size();

	sum = 0;
	bool flag = false;//记录第二层循环每次是因为sum达到跳出还是因为达不到自然执行完毕
	int count = 0;//记录每一次的加上新加元素，能达到sum的个数

	for (int i = 1; i < dp.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			sum += nums[j];
			if (sum >= s)
			{
				count++;
				flag = true;
				break;
			}
			else
				count++;
		}
		if (flag && count < dp[i - 1])
		{
			dp[i] = count;
		}
		else
		{
			dp[i] = dp[i - 1];
		}

		sum = 0; count = 0; flag = false;
	}
	return dp[dp.size() - 1];
}

//更好的方法是用双指针法
int minSubArrayLen(int s, vector<int>& nums) {
	int size = nums.size();
	if (size == 0){
		return 0;
	}
	int minLen = size + 1;
	int sum = 0;
	int start = 0, end = 0;
	while (end<size){
		while (sum<s && end<size){
			sum += nums[end];
			end++;
		}
		while (sum >= s){
			minLen = min(minLen, end - start);
			if (minLen == 1){
				return minLen;
			}
			sum -= nums[start];
			start++;
		}
	}

	return minLen == size + 1 ? 0 : minLen;
}