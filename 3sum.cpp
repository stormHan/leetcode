<<<<<<< HEAD
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
					index.push_back(nums[n]);
					index.push_back(nums[i]);
				}

			}

		}
		return index;
	}

	void InsertSort(vector<int> &a, int n)
	{
		int temp;
		for (int i = 1; i < n; ++i)
		{
			temp = a[i];
			int j;
			for (j = i; j > 0 && temp < a[j - 1]; --j)
			{
				a[j] = a[j - 1];
			}
			a[j] = temp;
		}
	}
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		nums = { 0, 0, 0 };
		vector<vector<int>> result;
		int length = result.size();
		if (length < 3)
		{
			return result;
		}

		InsertSort(nums, length);

		for (int i = 0; i < length - 2; ++i)
		{
			//去重
			if (i = !0)
			{
				if (nums[i] == nums[i + 1])
					continue;
			}
			vector<int> temp;
			for (int j = i + 1; j < length; ++i)
			{
				temp.push_back(nums[j]);
			}
			vector<int> temp_res = twoSum(temp, -nums[i]);
			int len = temp_res.size();
			if (len != 0)
			{
				vector<int > t;
				t.push_back(nums[i]);
				t.push_back(temp_res[len - 1]);
				t.push_back(temp_res[len - 2]);
				len = len - 2;

				result.push_back(t);
			}
		}

		return result;

	}

	vector<vector<int> > threeSum1(vector<int> &num) {
		// IMPORTANT: Please reset any member data you declared, as  
		// the same Solution instance will be reused for each test case.  

		vector<vector<int>> res;

		if (num.size() < 3)  //小于3个数  
			return res;

		//对原数组非递减（递增）排序  
		InsertSort(num, num.size());

		for (int i = 0; i < num.size(); ++i)
		{
			//去重  
			if (i != 0 && num[i] == num[i - 1])
				continue;

			int p = i + 1, q = num.size() - 1;
			int sum = 0;

			//收缩法寻找第2，第3个数  
			while (p < q)
			{
				sum = num[i] + num[p] + num[q];

				if (sum == 0)
				{
					vector<int> newRes;
					newRes.push_back(num[i]);
					newRes.push_back(num[p]);
					newRes.push_back(num[q]);
					InsertSort(newRes, newRes.size());
					res.push_back(newRes);


					//寻找其他可能的2个数，顺带去重  
					while (++p < q  && num[p - 1] == num[p])
					{
						//do nothing  
					}
					while (--q > p && num[q + 1] == num[q])
					{
						//do noghing  
					}
				}
				else if (sum < 0)  //和太小，p向后移动  
				{
					++p;
				}
				else            //和过大，q向前移动  
				{
					--q;
				}
			}
		}

		return res;
	}
=======
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
					index.push_back(nums[n]);
					index.push_back(nums[i]);
				}

			}

		}
		return index;
	}

	void InsertSort(vector<int> &a, int n)
	{
		int temp;
		for (int i = 1; i < n; ++i)
		{
			temp = a[i];
			int j;
			for (j = i; j > 0 && temp < a[j - 1]; --j)
			{
				a[j] = a[j - 1];
			}
			a[j] = temp;
		}
	}
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		nums = { 0, 0, 0 };
		vector<vector<int>> result;
		int length = result.size();
		if (length < 3)
		{
			return result;
		}

		InsertSort(nums, length);

		for (int i = 0; i < length - 2; ++i)
		{
			//去重
			if (i = !0)
			{
				if (nums[i] == nums[i + 1])
					continue;
			}
			vector<int> temp;
			for (int j = i + 1; j < length; ++i)
			{
				temp.push_back(nums[j]);
			}
			vector<int> temp_res = twoSum(temp, -nums[i]);
			int len = temp_res.size();
			if (len != 0)
			{
				vector<int > t;
				t.push_back(nums[i]);
				t.push_back(temp_res[len - 1]);
				t.push_back(temp_res[len - 2]);
				len = len - 2;

				result.push_back(t);
			}
		}

		return result;

	}

	vector<vector<int> > threeSum(vector<int> &num) {
		// IMPORTANT: Please reset any member data you declared, as  
		// the same Solution instance will be reused for each test case.  

		vector<vector<int>> res;

		if (num.size() < 3)  //小于3个数  
			return res;

		//对原数组非递减（递增）排序  
		InsertSort(num, num.size());

		for (int i = 0; i < num.size(); ++i)
		{
			//去重  
			if (i != 0 && num[i] == num[i - 1])
				continue;

			int p = i + 1, q = num.size() - 1;
			int sum = 0;

			//收缩法寻找第2，第3个数  
			while (p < q)
			{
				sum = num[i] + num[p] + num[q];

				if (sum == 0)
				{
					vector<int> newRes;
					newRes.push_back(num[i]);
					newRes.push_back(num[p]);
					newRes.push_back(num[q]);
					InsertSort(newRes, newRes.size());
					res.push_back(newRes);


					//寻找其他可能的2个数，顺带去重  
					while (++p < q  && num[p - 1] == num[p])
					{
						//do nothing  
					}
					while (--q > p && num[q + 1] == num[q])
					{
						//do noghing  
					}
				}
				else if (sum < 0)  //和太小，p向后移动  
				{
					++p;
				}
				else            //和过大，q向前移动  
				{
					--q;
				}
			}
		}

		return res;
	}
>>>>>>> 62ecb277e79aab08296e767ad6966f02a9fcf0f1
};