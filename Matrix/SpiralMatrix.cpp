/*---------------leetcode-----------------
---------------Level : Meidum-------------
---------------Spiral Matrix--------------
----------------storm Han-----------------
----------------2016.03.27----------------

Question describing:
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].


*/
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ret;
	int m = matrix.size();
	if (m == 0) return ret;

	int n = matrix[0].size();
	vector<vector<bool>> flag;
	for (int i = 0; i < m; i++)
	{
		vector<bool> temp;
		for (int j = 0; j < n; j++)
		{
			temp.push_back(false);
		}
		flag.push_back(temp);
	}

	int i = 0;
	int j = 0;
	int a = 0;

	while (ret.size() == m * n)
	{
		
		switch (a % 4)
		{
		case 0: 
			ret.push_back(matrix[i][j]);
			flag[i][j] = true;
			if (j = n - 1)
			{
				a++;
				if (i < m - 1)
				{
					if (!flag[i + 1][j])
						i++;
				}
				break;
			}
			else if (flag[i][j + 1]){
				a++;
				if (i == m - 1)
				{
					if (!flag[i + 1][j])
						i++;
				}
				break;
			}
			else
			{
				j++; break;
			}
		case 1:
			ret.push_back(matrix[i][j]);
			flag[i][j] = true;
			if (i == m - 1)
			{
				a++;
				if (j > 0)
				{
					if (!flag[i][j - 1])
						j--;
				}
				break;
			}
			else if (flag[i + 1][j]){
				a++;
				if (j > 0)
				{
					if (!flag[i][j - 1])
						j--;
				}
				break;
			}
			else
			{
				i++; break;
			}
		case 2:
			ret.push_back(matrix[i][j]);
			flag[i][j] = true;
			if (j == 0)
			{
				a++;
				if (i > 0)
				{
					if (!flag[i - 1][j])
						i--;
				}
				break;
			}
			else if (flag[i][j - 1]){
				a++;
				if (i > 0)
				{
					if (!flag[i - 1][j])
						i--;
				}
				break;
			}
			else
			{
				j--; break;
			}
		case 3:
			ret.push_back(matrix[i][j]);
			flag[i][j] = true;
			if (i == 0)
			{
				a++;
				if (j < n - 1)
				{
					if (!flag[i][j + 1])
						j++;
				}
				break;
			}
			else if (flag[i - 1][j]){
				a++;
				if (j < n - 1)
				{
					if (!flag[i][j + 1])
						j++;
				}
				break;
			}
			else
			{
				i--; break;
			}
		default:
			break;
		}
	}
}