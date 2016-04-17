/*
-------------LeetCode-----------------
-------------Storm han----------------
-----------Climbing Stairs------------
------------2016.04.17----------------

Decription:
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <vector>

using namespace std;

int climbStairs(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}