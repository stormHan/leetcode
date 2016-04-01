/*---------------leetcode-----------------
---------------Level : Medium-------------
--------------Permutationos---------------
----------------storm Han-----------------
----------------2016.03.25----------------

Question describing:
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Subscribe to see which companies asked this question

*/
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& ret, vector<int>& nums, int cur)
{
	if (cur == nums.size())
		ret.push_back(nums);
	else
	{
		for (int i = cur; i < nums.size(); i++)
		{
			swap(nums[cur], nums[i]);
			dfs(ret, nums, cur + 1);
			swap(nums[i], nums[cur]);
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ret;
	dfs(ret, nums, 0);
	
	return ret;
}