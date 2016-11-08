/*---------------leetcode-----------------
---------------Level : Hard---------------
-------- Longest Palindromic Substring ---
----------------storm Han-----------------
----------------2016.11.8-----------------
Question describing:
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"
*/

/*
	注意字符串中的dp方式！

*/
#include "main.h"

int numDistinct(string s, string t) {
	int lenS = s.size();
	int lenT = t.size();

	if (lenS < lenT) return 0;
	if (lenS == lenT)
		if (s == t) return 1;
		else return 0;

		//dp[i][j] 表示从s(i)->t(j)不同删除元素的方法数量
		vector<vector<int>> dp(lenS + 1, vector<int>(lenT + 1, 0));

		for (int i = 0; i <= lenS; ++i) dp[i][0] = 1;

		for (int i = 1; i <= lenS; ++i)
		{
			for (int j = 1; j <= lenT; ++j)
			{
				if (j > i) break;

				if (s[i - 1] == t[j - 1])
				{
					//表示是否使用s[i-1]和t[j-1]作为匹配，如果匹配则数量和dp[i-1][j-1]相同，否则
					//即在s[i-1]中找到整个t[j]，则数量为dp[i-1][j]
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}

			}
		}

		return dp[lenS][lenT];
}