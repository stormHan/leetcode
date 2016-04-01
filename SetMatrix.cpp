/*---------------leetcode-----------------
---------------Level : Meidum-------------
-------------Set Matrix Zero--------------
----------------storm Han-----------------
----------------2016.03.27----------------

Question describing:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Subscribe to see which companies asked this question

*/
#include <vector>

using namespace std;

void setZero(vector<vector<int>>& matrix, int a, int b)
{
	int m = matrix.size();
	int n = matrix[0].size();

	for (int i = 0; i < m; i++)
	{
		matrix[i][b] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		matrix[a][i] = 0;
	}
}

void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size();
	if (m > 0)
	{
		int n = matrix[0].size();
		vector<vector<int>> index;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);

					index.push_back(temp);
				}
			}
		}

		for (int i = 0; i < index.size(); i++)
		{
			setZero(matrix, index[i][0], index[i][1]);
		}
	}
}