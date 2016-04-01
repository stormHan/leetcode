/*---------------leetcode-----------------
---------------Back Tracing---------------
----------------Unique Path---------------
----------------storm Han-----------------
----------------2016.03.26----------------

Question describing:
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/
#include <stdio.h>
#include <vector>

using namespace std;

//用回溯法，果断超时。
void backTracing1(int& p, int cur, int step, int x, int y, int m, int n)
{
	if (cur == step)
	{
		p++;
	}
	else
	{
		if (x < n - 1) backTracing1(p, cur + 1, step, x + 1, y, m, n);
		if (y < m - 1) backTracing1(p, cur + 1, step, x, y + 1, m, n);
	}
}

int uniquePaths1(int m, int n) {
	int step = m + n - 2;
	if (step == 0) return 0;
	int p = 0;


	backTracing1(p, 0, step, 0, 0, m, n);

	return p;
}

//改用动态规划
//  递推方程式A[i][j] = A[i-1][j] + A[i][j-1] 最后返回A[m-1][n-1]即可

int uniquePaths(int m, int n) {
	vector<vector<int>> A;

	for (int i = 0; i < m; i++)
	{
		vector<int> temp;

		for (int j = 0; j < n; j++)
		{
			temp.push_back(0);
		}
		A.push_back(temp);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				A[i][j] = 1;
			else if(i == 0)
			{
				A[i][j] = A[i][j - 1];
			}
			else if (j == 0)
			{
				A[i][j] = A[i - 1][j];
			}
			else
			{
				A[i][j] = A[i - 1][j - 1];
			}

		}
	}
	return A[m - 1][n - 1];
}