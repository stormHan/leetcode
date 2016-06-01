/*---------------leetcode-----------------
---------------Level : Medium-------------
---------------Min Rectangle--------------
----------------storm Han-----------------
----------------2016.06.01----------------

Question describing:
Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing all ones and return its area.
*/
#include <vector>
using namespace std;
struct Coords
{
	int x;
	int y;

	Coords(int _a, int _b) :x(_a), y(_b){};
};
int maximalRectangle(vector<vector<char>>& matrix) {
	int h = matrix.size();
	if (h == 0) return 0;
	int w = matrix[0].size();

	Coords leftup(h, w);
	Coords rightdown(0, 0);

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (matrix[i][j] == '1')
			{
				if (leftup.x > i) leftup.x = i;
				if (leftup.y > j) leftup.y = j;
				if (rightdown.x < i) rightdown.x = i;
				if (rightdown.y < j) rightdown.y = j;
			}
		}
	}
	if (rightdown.x < leftup.x || rightdown.y < leftup.y) return 0;
	return (rightdown.x - leftup.x + 1) * (rightdown.y - leftup.y + 1);
}