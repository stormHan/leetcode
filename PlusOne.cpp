/*---------------leetcode-----------------
---------------Level : Easy---------------
------------------Plus One----------------
----------------storm Han-----------------
----------------2016.05.07----------------

Question describing:
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/

#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	int length = digits.size();

	if (length == 0) return digits;

	vector<int> ret(length + 1, 0);

	int cur = length - 1;
	int CF = 0;
	digits[cur] ++;
	while (cur >= 0)
	{
		if (digits[cur] + CF >= 10)
		{
			ret[cur + 1] = (digits[cur] + CF) % 10;
			CF = 1;
		}
		else
		{
			ret[cur + 1] = digits[cur] + CF;
			CF = 0;
		}
		cur--;
	}
	if (CF == 1) ret[0] = 1;
	else
	{
		vector<int>::iterator iter = ret.begin();
		ret.erase(iter);
	}

	return ret;


}