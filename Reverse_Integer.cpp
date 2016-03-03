#include <stdio.h>
#include <math.h>

class Solution {
public:
	int reverse(int x) {
		int result = 0;
		bool flag = true;
		int length = 1;//�۲�x�Ǽ�λ��
		if (x == 0)
			return 0;
		else if (x < 0)
		{
			flag = false;
			x = -x;
		}
		//ת��
		int storeX = x;
		while (x / 10 != 0){
			x = x / 10;
			length++;
		}
		x = storeX;

		for (int i = 0; i < length; i++)
		{
			int a = x % 10;
			result += a * pow((double)10, (int)length - i - 1);
			x = x / 10;
		}

		if (result > 0 && storeX < 0)return 0;
		if (result < 0 && storeX > 0)return 0;
		//if (result == -2147483648) return 0;

		if (!flag)
			return -result;
		else
			return result;
	}

	int answer_reverse(int x){
		const int max = 0x7fffffff; //int ���ֵ
		const int min = 0x80000000; //int ��Сֵ

		long long sum = 0;

		while (x != 0)
		{
			int temp = x % 10;
			sum = sum * 10 + temp;
			if (sum > max || sum < min) //�������
			{
				sum = sum > 0 ? max : min;
				return sum;
			}
			x = x / 10;
		}
		return sum;
	}
};