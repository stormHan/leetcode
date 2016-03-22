/*---------------leetcode-----------------
-----------ExcelSheetColumnNumber---------
----------------storm Han-----------------
----------------2016.03.22----------------

Question describing:
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28

*/    
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int titleToNumber(string s) {
	int length = s.size();

	if (length == 0) return 0;

	int result = 0;
	const char* c = s.c_str();

	for (int i = 0; i < length; i++)
	{
		if (c[i] < 'A' || c[i] > 'Z')
			exit(0);
		int temp = c[i] - 'A' + 1;
		result += temp * pow(26.0f, length - 1);
	}

	return result;
}

string convertToTitle1(int n) {
	string s;
	char* c, *p;


	if (n <= 0) return s;

	int b = n; int i = 0, j = 0;
	int temp;
	do
	{
		temp = b;
		int a = b % 26;
		if (a == 0) a = 26;
		b = (b - a) / 26;
		i++;
	} while (b > 0 && temp != 26);

	c = new char[i];
	p = new char[i];

	do
	{
		temp = n;
		int a = n % 26;
		if (a == 0)
			a = 26;

		c[j] = 'A' + a - 1;

		n = (n - a) / 26;
		j++;
	} while (n > 0 && temp != 26);

	for (int j = 0; i > 0; j++)
	{
		p[j] = c[i - 1];
		i--;
	}

	s = p;
	int ss = s.size();
	return s;
}