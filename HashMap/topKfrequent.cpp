/*---------------leetcode-----------------
---------------Level : Medium-------------
----------- Top K frequent number---------
----------------storm Han-----------------
----------------2016.11.3----------------
Question describing:
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

/*
	sort 的cmp函数一定要加static
	vector<pair<int, int>>形式
*/

#include "main.h"

static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	map<int, int>  hashmap;
	vector<int> ret;

	if (k == 0) return ret;

	for (int i = 0; i<nums.size(); ++i)
	{
		if (hashmap.count(nums[i]) == 0)
		{
			hashmap.insert(pair<int, int>(nums[i], 1));
		}
		else
			hashmap[nums[i]]++;
	}

	vector<pair<int, int>> m2;
	for (map<int, int>::iterator iter = hashmap.begin(); iter != hashmap.end(); ++iter)
	{
		m2.push_back(pair<int, int>(iter->second, iter->first));
	}
	sort(m2.begin(), m2.end(), cmp);

	for (int i = 0; i<k; ++i)
	{
		ret.push_back(m2[i].second);
	}
	return ret;
}