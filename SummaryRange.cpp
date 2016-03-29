/*---------------leetcode-----------------
---------------Level : Easy---------------
---------------Summary Ranges-------------
----------------storm Han-----------------
----------------2016.03.27----------------

Question describing:

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","

*/

#include <vector>
#include <string>

using namespace std;

vector<string> summaryRange(vector<int> nums)
{
	vector<string> ret;
	string temp;
	bool f = true;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (f)
		{
			char t[256];
			string s;

			sprintf(t, "%d", nums[i]);
			s = t;

			temp += s;
			if (i == nums.size() - 1)
			{
				ret.push_back(temp);
				break;

			}
			if (nums[i] != nums[i + 1] - 1)
			{
				ret.push_back(temp);
				temp = "";
			}
			else {
				temp += "->";
				f = !f;
			}
		}
		if (!f){
			if (i != nums.size() - 1)
			{
				if (nums[i] == nums[i + 1] - 1)
				{
				}
				else
				{
					char t1[256];
					string s1;

					sprintf(t1, "%d", nums[i]);
					s1 = t1;

					temp += s1;
					ret.push_back(temp);
					temp = "";
					f = !f;
				}
			}
			else
			{
				char t2[256];
				string s2;

				sprintf(t2, "%d", nums[i]);
				s2 = t2;

				temp += s2;
				ret.push_back(temp);
			}

		}
	}

	return ret;
}