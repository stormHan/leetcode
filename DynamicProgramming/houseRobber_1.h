/*---------------leetcode-----------------
---------------House Robber---------------
------------Dynamic Programming-----------
----------------storm Han-----------------
----------------2016.03.19----------------

Question describing:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected ,
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

//�����Ҳ��ᣬ��������
//��̬�滮�� ����maxV[i]��ʾ����i������λ��ʱ��������棬����
//���ƹ�ϵΪmaxV[i] = max( maxV[i - 2] + nums[i] , maxV[i - 1])

#include <vector>

using namespace std;
/*
������Կ����Ǽ򵥵�DP���⣬��A[0]��ʾû��rob��ǰhouse�����money��A[1]��ʾrob�˵�ǰhouse�����money����ôA[0] ����rob����û��rob��һ��house�����ֵ
��A[i+1][0] = max(A[i][0], A[i][1])..  ��ôrob��ǰ��house��ֻ�ܵ����ϴ�û��rob��+money[i+1], ��A[i+1][1] = A[i][0]+money[i+1].
ʵ����ֻ��Ҫ���������������Ϳ����ˣ�����Ҫ�ö�ά����
*/
int max(int a, int b)
{
	if (a > b)return a;
	else
	{
		return b;
	}
}

int rob(vector<int> &nums)
{
	int best0 = 0;//û��ѡ��ǰhouse���������
	int best1 = 0;//�Ѿ�ѡ��ǰhouse���������

	for (int i = 0; i < nums.size(); i++)
	{
		int temp = best0;
		best0 = max(best0, best1);
		best1 = temp + nums[i];
	}
	return max(best0, best1);
}