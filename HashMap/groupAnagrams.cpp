#include "main.h"

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<string> ts = strs;
	vector<vector<string>> ret;
	map<string, vector<string>> hashmap;

	if (strs.size() == 0) return ret;
	for (int i = 0; i < strs.size(); ++i)
	{
		sort(strs[i].begin(), strs[i].end());
	}

	for (int i = 0; i < strs.size(); ++i)
	{
		if (hashmap.count(strs[i]) == 0)
		{
			vector<string> vec_s;
			vec_s.push_back(ts[i]);
			hashmap.insert(pair<string, vector<string>>(strs[i], vec_s));
		}
		else
			hashmap[strs[i]].push_back(ts[i]);
	}

	for (map<string, vector<string>>::iterator iter = hashmap.begin(); iter != hashmap.end(); ++iter)
	{
		sort(iter->second.begin(), iter->second.end());
		ret.push_back(iter->second);
	}

	return ret;
}