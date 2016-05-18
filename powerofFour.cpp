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

//�ж�һ�����Ƿ���2���ݣ��жϷ�����Ҫ����2��N���ݵ��ص㣺������λΪ1�������λ��Ϊ0.
//����1�� n & n - 1 == 0
//[cpp] view plain copy print ?
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n>0) && (!(n&(n - 1)));
	}

	//�ж϶�������1�ĸ���
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
//������ĿҪ����ò�Ҫ��ѭ�������ж�������ǲ���2��Power���ٿ�1�Ƿ����������λ��
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