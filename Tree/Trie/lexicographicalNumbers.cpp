/*---------------leetcode-----------------
---------------Level : Medium-------------
----------- Lexicographical Numbers ------
----------------storm Han-----------------
----------------2016.11.6----------------

Question describing:
1,
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9].

Please optimize your algorithm to use less time and space.The input size may be as large as 5, 000, 000.

2,
Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

Note: 1 ≤ k ≤ n ≤ 109.
*/

//我的超时思路

#include "main.h"

string toString(int a)
{
	string s1, s2;
	int t;
	while (a != 0)
	{
		t = a % 10;
		s1.push_back(t + '0');
		a /= 10;
	}
	for (int i = s1.size() - 1; i >= 0; --i)
	{
		s2.push_back(s1[i]);
	}
	return s2;
}

int toInt(string s)
{
	int ret = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		ret *= 10;
		ret += (s[i] - '0');
	}
	return ret;
}
static bool cmp(const string& lhs, const string& rhs)
{
	int i = 0;
	while (i < lhs.size() && i < rhs.size())
	{
		if (lhs[i] < rhs[i]) return true;
		else if (lhs[i] > rhs[i]) return false;
		else i++;
	}
	if (i < lhs.size()) return false;
	return true;
}

int findKthNumber(int n, int k) {
	string ts;
	vector<string> vec_s;
	for (int i = 1; i <= n; ++i)
	{
		ts = toString(i);
		vec_s.push_back(ts);
	}

	sort(vec_s.begin(), vec_s.end(), cmp);
	return toInt(vec_s[k - 1]);
}

//正确答案，很巧妙的运用了字典数列的规律！！！仔细体会
vector<int> lexicalOrder(int n) {
	vector<int> ret(n);

	int cur = 1;
	for (int i = 0; i < ret.size(); ++i)
	{
		ret[i] = cur;

		if (cur * 10 <= n) cur *= 10;
		else
		{
			if (cur == n) cur /= 10;
			cur += 1;
			while (cur % 10 == 0) cur /= 10;
		}
	}
	return ret;
}