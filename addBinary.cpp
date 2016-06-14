/*---------------leetcode-----------------
---------------Level : Easy---------------
----------------Add  Binary---------------
----------------storm Han-----------------
----------------2016.06.14----------------

Question describing:
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include <string>

using namespace std;

string addBinary(string a, string b) {
	int lenA = a.size();
	int lenB = b.size();

	string ret(((lenA > lenB) ? (lenA + 1) : lenB + 1), 0);

	int cf = 0, i = lenA - 1, j = lenB - 1;
	int k = (i > j) ? i + 1 : j + 1;
	while (i >= 0 || j >= 0)
	{
		int _a, _b;
		if (a[i] == '0' || i < 0) _a = 0;
		else _a = 1;

		if (b[j] == '0' || j < 0) _b = 0;
		else _b = 1;

		switch (_a + _b + cf)
		{
		case 3: cf = 1; ret[k] = '1'; break;
		case 2: cf = 1; ret[k] = '0'; break;
		case 1: cf = 0; ret[k] = '1'; break;
		case 0: cf = 0; ret[k] = '0'; break;
		}

		i--; j--; k--;
	}

	if (cf == 1) ret[0] = '1';
	else
	{
		ret.erase(ret.begin());
	}

	return ret;
}