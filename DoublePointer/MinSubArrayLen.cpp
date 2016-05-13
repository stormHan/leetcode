/*---------------leetcode-----------------
-----------Min Size Subarray Length-------
----------------storm Han-----------------
----------------2016.05.10----------------

Question describing:
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum �� s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

*/
#include <vector>

using namespace std;

//�ҵķ���,DP
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
	bool flag = false;//��¼�ڶ���ѭ��ÿ������Ϊsum�ﵽ����������Ϊ�ﲻ����Ȼִ�����
	int count = 0;//��¼ÿһ�εļ����¼�Ԫ�أ��ܴﵽsum�ĸ���

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

//���õķ�������˫ָ�뷨
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