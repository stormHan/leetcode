#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index;
		map<int, int> hmap;

		for (int i = 0; i < nums.size(); i++)
		{
			if (!hmap.count(nums.at(i)))
				hmap.insert(pair<int, int>(nums.at(i), i));
			if (hmap.count(target - nums.at(i)))
			{
				int n = hmap[target - nums.at(i)];
				if (n < i)
				{
					index.push_back(n);
					index.push_back(i);
				}

			}

		}
		return index;
	}