/*---------------leetcode-----------------
---------------pascal's Triangle----------s
----------------storm Han-----------------
----------------2016.03.31----------------

Question describing:
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return


[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	
	for (int i = 0; i < numRows; ++i)
	{
		vector<int> temp;
		if (i == 0)
		{
			temp.push_back(1);
		}
		else if (i == 1)
		{
			temp.push_back(1);
			temp.push_back(1);
		}
		else
		{
			for (int j = 0; j < i + 1; ++j)
			{
				if (j == 0)
					temp.push_back(1);
				else if (j == i)
				{
					temp.push_back(1);
				}
				else
				{
					temp.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
				}
			}
		}
	}

	return ret;
}

vector<int> getRow2(int rowIndex) {
	vector<int> result(rowIndex + 2, 0);
	result[1] = 1;
	for (int i = 0; i<rowIndex; i++){
		for (int j = rowIndex + 1; j>0; j--){
			result[j] = result[j - 1] + result[j];
		}
	}
	result.erase(result.begin());
	return result;
}