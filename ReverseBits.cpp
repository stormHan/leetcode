/*---------------leetcode-----------------
---------------Level : Easy---------------
---------------Reverse Bits---------------
----------------storm Han-----------------
----------------2016.05.18----------------

Question describing:
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
return 964176192 (represented in binary as 00111001011110000010100101000000).
*/

#include <stdint.h>
#include <vector>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
	vector<int> vec1(32, 0);

	//��n�Ķ����Ʊ�ʾ���������һ��vector��
	int i = 0;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			vec1[i] = 1;
		}
		n /= 2;
		i++;
	}

	i -= 1;
	//����µ����������Ѿ����0��n��
	while (i >= 0)
	{
		if (vec1[i] == 1)
		{
			n += pow((double)2, 31 - i);
		}
		i--;
	}
	return n;
}