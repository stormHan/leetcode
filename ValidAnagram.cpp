/*---------------leetcode-----------------
---------------Valid Anagram--------------
----------------storm Han-----------------
----------------2016.04.07----------------

Question describing:
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//My Algorithm 
bool isAnagram(string s, string t) {
	if (s.size() != t.size())
		return false;
	int length = s.size();

	for (int i = 0; i < length; ++i)
	{
		if (s[i] != t[i])
		{
			if (i == length - 1) return false;

			for (int j = i + 1; j < length; ++j)
			{
				if (t[j] != s[i] && j == length - 1)
				{
					return false;
				}
				else if (t[j] == s[i])
				{
					char temp = t[i];
					t[i] = t[j];
					t[j] = temp;
					break;
				}
			}
		}
	}
	return true;
}
//sort first. better than my algorithm, not that good
bool isAnagram1(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	return s == t;
}

//Hash better
bool isAnagram2(string s, string t){
	vector<int> count(26, 0);
	for (int i = 0; i < s.size(); i++)
		count[s[i] - 'a'] ++;
	for (int i = 0; i < t.size(); i++)
		count[t[i] - 'a'] --;
	for (int i = 0; i < 26; i++)
		if (count[i] != 0)
			return false;
	return true;
}