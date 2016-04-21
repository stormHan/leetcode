/*
 Stormhan
 
  2016.04.21

  find a Duplicate in a vector;
  
  */
#include<vector>
#include <map>

using namespace std;

int findDuplicate(vector<int>& nums) {
	map<int, int> hmap;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (hmap.count(nums[i]) > 0) return nums[i];
		else
		{
			hmap.insert(pair<int, int>(nums[i], 1));
		}
	}
}