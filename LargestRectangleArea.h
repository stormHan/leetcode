<<<<<<< HEAD
﻿/*---------------leetcode-----------------
---------------Level : Hard---------------
-----------Largest Rectangle Area---------
----------------storm Han-----------------
----------------2016.03.17----------------

Question describing:
	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
	find the area of largest rectangle in the histogram.

*/

//我的方法，能实现相应的功能，但是超时了 O(n^2)
//通过剪枝优化.
#include <stack>
#include <cmath>
int FindLargestArea(vector<int> heights)
{
	if (heights.size() == 0)
	{
		return 0;
	}

	if (heights.size() == 1)
	{
		return heights[0];
	}

	int MaxArea = 0;

	for (int i = 0; i < heights.size(); i++)
	{
		int temp_area = heights[i];
		int j = i + 1, k = i -1;
		while (j < heights.size())
		{
			
			if (heights[j] >= heights[i])
			{
				temp_area += heights[i];
			}
			else 
			{
				break;
			}
			j++;
		}

		while (k > -1)
		{
			if (heights[k] >= heights[i])
			{
				temp_area += heights[i];
			}
			else
			{
				break;
			}
			k--;
		}
		if (temp_area > MaxArea)
			MaxArea = temp_area;
	}

	return MaxArea;
}

int FindLargestArea_pruning(vector<int> heights)
{
	if (heights.size() == 0)
	{
		return 0;
	}

	if (heights.size() == 1)
	{
		return heights[0];
	}

	int area = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		for (int j = i + 1; j < heights.size(); j++)
		{
			if (heights[j] < heights[j - 1])
			{
				i = j - 1;
				break;
			}
			else{
				i = j;
			}
		}

		int lowest = heights[i];
		if (lowest > area)
			area = lowest;

		for (int j = i - 1; j >= 0; j--)
		{
			if (heights[j] < lowest)
				lowest = heights[j];

			int currArea = (i - j + 1) * lowest;
			if (currArea > area)
				area = currArea;
		}

	}
	return area;
}

//int largestRectangleArea(vector<int> &height) {
//	if (height.size() == 0) return 0;
//
//	int res = 0;
//	vector<int> tmp = height;
//	tmp.push_back(0);  // Important
//
//	stack<int> s;
//	for (int i = 0; i < tmp.size(); i++)
//	{
//		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) s.push(i);
//		else{
//			while (!s.empty() && tmp[s.top()] > tmp[i])
//			{
//				int idx = s.top(); s.pop();
//				int width = s.empty() ? i : (i - s.top() - 1);
//				res = max(res, tmp[idx] * width);
//			}
//			s.push(i);  // Important
//		}
//	}
//	return res;
//}
=======
﻿/*---------------leetcode-----------------
---------------Level : Hard---------------
-----------Largest Rectangle Area---------
----------------storm Han-----------------
----------------2016.03.17----------------

Question describing:
	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
	find the area of largest rectangle in the histogram.

*/

//我的方法，能实现相应的功能，但是超时了 O(n^2)
//通过剪枝优化.
#include <stack>
#include <cmath>
int FindLargestArea(vector<int> heights)
{
	if (heights.size() == 0)
	{
		return 0;
	}

	if (heights.size() == 1)
	{
		return heights[0];
	}

	int MaxArea = 0;

	for (int i = 0; i < heights.size(); i++)
	{
		int temp_area = heights[i];
		int j = i + 1, k = i -1;
		while (j < heights.size())
		{
			
			if (heights[j] >= heights[i])
			{
				temp_area += heights[i];
			}
			else 
			{
				break;
			}
			j++;
		}

		while (k > -1)
		{
			if (heights[k] >= heights[i])
			{
				temp_area += heights[i];
			}
			else
			{
				break;
			}
			k--;
		}
		if (temp_area > MaxArea)
			MaxArea = temp_area;
	}

	return MaxArea;
}

int FindLargestArea_pruning(vector<int> heights)
{
	if (heights.size() == 0)
	{
		return 0;
	}

	if (heights.size() == 1)
	{
		return heights[0];
	}

	int area = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		for (int j = i + 1; j < heights.size(); j++)
		{
			if (heights[j] < heights[j - 1])
			{
				i = j - 1;
				break;
			}
			else{
				i = j;
			}
		}

		int lowest = heights[i];
		if (lowest > area)
			area = lowest;

		for (int j = i - 1; j >= 0; j--)
		{
			if (heights[j] < lowest)
				lowest = heights[j];

			int currArea = (i - j + 1) * lowest;
			if (currArea > area)
				area = currArea;
		}

	}
	return area;
}

int largestRectangleArea(vector<int> &height) {
	if (height.size() == 0) return 0;

	int res = 0;
	vector<int> tmp = height;
	tmp.push_back(0);  // Important

	stack<int> s;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) s.push(i);
		else{
			while (!s.empty() && tmp[s.top()] > tmp[i])
			{
				int idx = s.top(); s.pop();
				int width = s.empty() ? i : (i - s.top() - 1);
				res = max(res, tmp[idx] * width);
			}
			s.push(i);  // Important
		}
	}
	return res;
}
>>>>>>> 62ecb277e79aab08296e767ad6966f02a9fcf0f1
