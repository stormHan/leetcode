/*---------------leetcode-----------------
---------------Single Number--------------
----------------storm Han-----------------
----------------2016.04.01----------------

Question describing:

Given an array of integers, every element appears twice except for one. Find that single one.

*/

#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int a = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		a = a ^ nums[i];
	}
	return a;
}