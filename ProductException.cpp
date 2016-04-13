/*---------------leetcode-----------------
---------------Level : Medium-------------
------------Product Except Self-----------
----------------storm Han-----------------
----------------2016.04.13----------------

Question describing:
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

*/
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> ret;
	if (nums.size() == 1)
	{
		ret.push_back(0);
		return ret;
	}
	if (nums.size() == 0)
	{
		return ret;
	}
	int sum = 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum *= nums[i];
	}
	if (sum == 0)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0) ret.push_back(0);
			else{
				int a = 1;
				for (int j = 0; j < nums.size(); ++j)
				{
					if (j != i) a *= nums[j];
				}
				ret.push_back(a);
			}
		}
	}
	else
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			ret.push_back(sum / nums[i]);
		}
	}
	return ret;
}

//若不用除法
/*
我们以一个4个元素的数组为例，nums=[a1, a2, a3, a4]。
想在O(n)时间复杂度完成最终的数组输出，res=[a2*a3*a4, a1*a3*a4, a1*a2*a4, a2*a3*a4]。

比较好的解决方法是构造两个数组相乘：

[1, a1, a1*a2, a1*a2*a3]
[a2*a3*a4, a3*a4, a4, 1]
这样思路是不是清楚了很多，而且这两个数组我们是比较好构造的。


但是，上面的空间复杂度为O(N)，不满足常数空间复杂度。我们可以对上面的代码进行空间优化，
用一个常数p来保存每次计算的结果值。
*/

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> res(nums.size(), 1);
	for (int i = 1; i < nums.size(); ++i) {
		res[i] = res[i - 1] * nums[i - 1];
	}
	int right = 1;
	for (int i = nums.size() - 1; i >= 0; --i) {
		res[i] *= right;
		right *= nums[i];
	}
	return res;
}