/*---------------leetcode-----------------
---------------Level : Medium-------------
---------------Missing Numebr-------------
----------------storm Han-----------------
----------------2016.04.15----------------

Question describing:

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

*/   

#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
int length = nums.size();
int sum = 0;
for (int i = 0; i < length; ++i)
{
	sum += nums[i];
}
return length * (length + 1) / 2 - sum;
	}