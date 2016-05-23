/*---------------leetcode-----------------
---------------Level : Easy---------------
---------------Power of Four--------------
----------------storm Han-----------------
----------------2016.05.18----------------

Question describing:
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
*/

bool isPowerOfFour(int num) {
	if (num == 0) return false;
	while (num != 1)
	{
		if (num % 4 != 0)
		{
			return false;
		}
		else
		{
			num /= 4;
		}
	}
	return true;
}

//判断一个数是否是2的幂，判断方法主要依据2的N次幂的特点：仅有首位为1，其余各位都为0.
//方法1： n & n - 1 == 0
//[cpp] view plain copy print ?
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n>0) && (!(n&(n - 1)));
	}

	//判断二进制中1的个数
	bool isPowerOfTwo_(int n) {
		int count = 0;
		while (n > 0)
		{
			count += (n & 0x01);
			n >>= 1;
		}
		return count == 1;
	}
};
//考虑题目要求最好不要用循环，先判断这个数是不是2的Power，再看1是否出现在奇数位上
bool isPowerOfFour_(int num) {
	if ((num&(num - 1)) == 0)
	{
		if (num & 0x55555555)
		{
			return true;
		}
	}
	return false;
}