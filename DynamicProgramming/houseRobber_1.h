/*---------------leetcode-----------------
---------------House Robber---------------
------------Dynamic Programming-----------
----------------storm Han-----------------
----------------2016.03.19----------------

Question describing:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected ,
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

//这题我不会，看答案做的
//动态规划， 设置maxV[i]表示到第i个房子位置时的最大收益，则有
//递推关系为maxV[i] = max( maxV[i - 2] + nums[i] , maxV[i - 1])

#include <vector>

using namespace std;
/*
这题可以看做是简单的DP问题，用A[0]表示没有rob当前house的最大money，A[1]表示rob了当前house的最大money，那么A[0] 等于rob或者没有rob上一次house的最大值
即A[i+1][0] = max(A[i][0], A[i][1])..  那么rob当前的house，只能等于上次没有rob的+money[i+1], 则A[i+1][1] = A[i][0]+money[i+1].
实际上只需要两个变量保存结果就可以了，不需要用二维数组
*/
int max(int a, int b)
{
	if (a > b)return a;
	else
	{
		return b;
	}
}

int rob(vector<int> &nums)
{
	int best0 = 0;//没有选择当前house的最佳收益
	int best1 = 0;//已经选择当前house的最佳收益

	for (int i = 0; i < nums.size(); i++)
	{
		int temp = best0;
		best0 = max(best0, best1);
		best1 = temp + nums[i];
	}
	return max(best0, best1);
}