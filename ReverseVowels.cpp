/*---------------leetcode-----------------
---------------Level : Medium-------------
------------Reverse Vowel of a STring-----
----------------storm Han-----------------
----------------2016.04.26----------------

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

*/
#include <set>
#include <string>

using namespace std; 

void SwapChar(string& s, int pos1, int pos2)
{
	char temp = s[pos1];
	s[pos1] = s[pos2];
	s[pos2] = temp;
}

string reverseVowels(string s)
{
	char base[10] = { 'a', 'o', 'e', 'u', 'i', 'A', 'O', 'E', 'U', 'I'};
	set<char> setting(base, base + 10);

	int startpos = 0;
	int endpos = s.size() - 1;
	
	while (startpos < endpos)
	{
		while (startpos < endpos && setting.find(s[startpos]) == setting.end())
			startpos++;
		while (startpos < endpos && setting.find(s[endpos]) == setting.end())
			endpos--;

		if (startpos < endpos) SwapChar(s, startpos++, endpos--);
	}
	return s;
}