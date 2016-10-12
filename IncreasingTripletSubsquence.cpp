/*---------------leetcode-----------------
---------------Level : Medium-------------
-------- Increasing Triplet Subsequence---
----------------storm Han-----------------
----------------2016.10.12----------------
Question describing:
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/


#include "main.h"
using namespace std;


bool increasingTriplet(vector<int>& nums) {
	int a1 = 0, a2 = 0, a3 = 0;
	int candidate_a1 = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] > nums[a1])
		{
			if (a2 == 0)
			{
				a2 = i;
			}
			if (nums[i] > nums[a2])
			{
				a3 = i;
				return true;
			}
			else
				a2 = i;
		}

		if (nums[i] < nums[a1] && (candidate_a1 == 0 || nums[i] < nums[candidate_a1]))
		{
			candidate_a1 = i;
			continue;
		}

		if (nums[i] <= nums[a1] && nums[i] > nums[candidate_a1])
		{
			a1 = candidate_a1;
			a2 = i;
		}
	}
	if (a3 == 0) return false;
	else return true;
}