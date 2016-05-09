/*---------------leetcode-----------------
------------Length of Last Word-----------
----------------storm Han-----------------
----------------2016.05.09----------------

Question describing:

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

#include <string>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
	int ret;
	bool flag = false;
	vector<string> store;

	string temp = "";
	for (int i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if (c == ' ')
		{
			if (flag)
			{
				store.push_back(temp);
				temp = "";
				flag = false;
			}
		}
		else
		{
			temp += c;
			flag = true;
		}
	}
	if (flag == true)
		store.push_back(temp);

	if (store.size() == 0) return 0;
	return store[store.size() - 1].size();
}