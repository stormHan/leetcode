/*---------------leetcode-----------------
-----Different Ways to add Parenthneses---
----------------storm Han-----------------
----------------2016.05.23----------------

Question describing:
Given a string of numbers and operators, return all possible results from computing
all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

*/
#include <vector>
#include <string>

using namespace std;

void dfs(int step, int n, vector<int> nums, vector<int> op, vector<int> &ret)
{
	if (step == n)
	{
		if (find(ret.begin(), ret.end(), nums[0]) == ret.end())
			ret.push_back(nums[0]);
	}
	else
	{
		vector<int> nums_str = nums;
		vector<int> op_str = op;
		for (int i = 0; i < n - step; ++i)
		{
			nums = nums_str;
			op = op_str;

			vector<int>::iterator iter1 = nums.begin();
			vector<int>::iterator iter2 = op.begin();
			int j = i;
			while (j > 0)
			{
				iter1++;
				iter2++;
				j--;
			}
			int a = *iter1;
			int b = *iter2;

			iter1 = nums.erase(iter1);
			op.erase(iter2);

			switch (b)
			{
			case 1: *iter1 += a; break;
			case 2: *iter1 = a - *iter1; break;
			case 3: *iter1 *= a; break;
			case 4: *iter1 = a / *iter1; break;

			default:
				break;
			}

			dfs(step + 1, n, nums, op, ret);
		}
	}

}

vector<int> diffWaysToCompute(string input) {
	int n = input.size() / 2;

	vector<int> nums;
	vector<int> operators;
	vector<int> ret;
	for (int i = 0; i < input.size(); ++i)
	{
		if (i % 2 == 0)
		{
			nums.push_back(input[i] - '0');
		}
		else
		{
			if (input[i] == '+')
				operators.push_back(1);
			else if (input[i] == '-')
				operators.push_back(2);
			else if (input[i] == '*')
				operators.push_back(3);
			else
				operators.push_back(4);
		}
	}

	dfs(0, n, nums, operators, ret);

	return ret;
}
