/*---------------leetcode-----------------
----------------Rotate Image--------------
----------------storm Han-----------------
----------------2016.03.21----------------

Question describing:
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int row = matrix.size();
	int col;
	if (row == 0)
	{
		return ;
	}
	else
	{
		col = matrix[0].size();
	}

	vector<vector<int>> temp;
	for (int i = 0; i < col; ++i)
	{
		vector<int > v;
		for (int j = row - 1; j >= 0; j--)
		{
			v.push_back(matrix[i][j]);
		}
		temp.push_back(v);
	}
	matrix = temp;
}
