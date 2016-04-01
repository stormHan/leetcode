/*---------------leetcode-----------------
-----------Zig Zag Converting-------------
----------------storm Han-----------------
----------------2016.03.23----------------

Question describing:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

*/

#include <string>

using namespace std;

string convert(string s, int numRows) {
	// IMPORTANT: Please reset any member data you declared, as  
	// the same Solution instance will be reused for each test case.    

	if (numRows <= 1 || s.length() == 0)
		return s;

	string res = "";
	int len = s.length();
	for (int i = 0; i < len && i < numRows; ++i)
	{
		int indx = i;
		res += s[indx];

		for (int k = 1; indx < len; ++k)
		{
			//第一行或最后一行，使用公式1：  
			if (i == 0 || i == numRows - 1)
			{
				indx += 2 * numRows - 2;
			}
			//中间行，判断奇偶，使用公式2或3  
			else
			{
				if (k & 0x1)  //奇数位  
					indx += 2 * (numRows - 1 - i);
				else indx += 2 * i;
			}

			//判断indx合法性  
			if (indx < len)
			{
				res += s[indx];
			}
		}
	}
	return res;
}