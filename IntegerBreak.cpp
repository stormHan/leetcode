/*---------------leetcode-----------------
---------------Level : Medium-------------
---------------Integer Break--------------
----------------storm Han-----------------
----------------2016.05.20----------------

Question describing:
Given a positive integer n, break it into the sum of at least two positive integers and maximize the 
product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.
*/
#include <vector>

using namespace std;

vector<int> huafen(int a, int n)
{
	vector<int> ret(n, (a / n));

	int num = a % n;
	while (num > 0)
	{
		ret[num] = ret[num] + 1;
		num--;
	}
	return ret;
}

int integerBreak(int n) {
	if (n == 2) return 1;
	if (n == 3) return 2;

	int maxvalue = 0;
	int v;
	vector<int> ans;
	for (int i = 2; i <= (n / 2); ++i)
	{
		ans = huafen(n, i);
		v = 1;
		for (int j = 0; j < ans.size(); ++j)
		{
			v *= ans[j];
		}
		if (v > maxvalue) maxvalue = v;
	}

	return maxvalue;
}