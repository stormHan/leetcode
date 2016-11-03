/*---------------leetcode-----------------
---------------Level : Medium-------------
-------- Longest Palindromic Substring ---
----------------storm Han-----------------
----------------2016.11.1----------------
Question describing:
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, a
nd there exists one unique longest palindromic substring.
*/

/*
	������ִ�
*/
#include "main.h"

//Ŀǰ��ֻ��leetcode��AC�˶�̬�滮������
//ʱ����죬�ռ��С���㷨Ӧ����manechor�㷨

string longestPalindrome(string s) {
	int lens = s.size();
	if (s.size() == 0 || s.size() == 1) return s;
	int begin = 0, length = 1;

	vector<vector<bool>> dp(lens, vector<bool>(lens, false));

	for (int i = 0; i < lens; ++i)
	{
		dp[i][i] = true;
	}
	for (int i = 0; i < lens - 1; ++i)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			begin = i;
			length = 2;
		}
	}
	for (int gap = 2; gap<lens; ++gap)
	{
		for (int i = 0; i + gap<lens; ++i)
		{
			if (s[i] == s[i + gap] && dp[i + 1][i + gap - 1] == true)
			{
				dp[i][i + gap] = true;
				begin = i;
				length = gap + 1;
			}
		}
	}
	return s.substr(begin, length);
}