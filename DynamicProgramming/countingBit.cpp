/*
-------------LeetCode-----------------
-------------Storm han----------------
-----------Counting bit---------------


Decription:
Given a non negative integer number num. For every numbers i in the range 0 ¡Ü i ¡Ü num calculate 
the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].
*/

#include <vector>

using namespace std;

vector<int> countBits(int num) {
	vector<int> ret(num + 1);
	ret[0] = 0;

	for (int i = 1; i <= num; ++i)
	{
		if (i % 2 == 0)
			ret[i] = ret[i / 2];
		else
			ret[i] = ret[i - 1] + 1;

	}
	return ret;
}