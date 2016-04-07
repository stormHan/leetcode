/*---------------leetcode-----------------
---------------Trailing Zeros-------------
----------------storm Han-----------------
----------------2016.04.07----------------

Question describing:
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

int trailingZeroes(int n) {
	int count_2 = 0;
	int count_5 = 0;

	while (n > 1)
	{
		int temp = n;
		while (temp % 5 == 0)
		{
			count_5++;
			temp = temp / 5;
		}
		temp = n;
		while (temp % 2 == 0)
		{
			count_2++;
			temp = temp / 2;
		}
		n--;
	}
	if (count_2 < count_5) return count_2;
	else return count_5;
}//��ʱ

//��Ϊȡ����5/2�еĽ�Сֵ����2�����ӿ϶���5Ҫ�࣬��ֻ����5���ɡ�
int trailingZeroes1(int n)
{
	int ret = 0;
	while (n > 0)
	{
		ret += n / 5;
		n /= 5;
	}
	return ret;
}