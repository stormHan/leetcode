/*---------------leetcode-----------------
---------------Level :  Hard--------------
----------- Top K frequent number---------
----------------storm Han-----------------
----------------2016.11.5----------------
Question describing:
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/*
sort 的cmp函数一定要加static
unordered_set 是不能<>自定义的类和pair<int, int>的

*/

#include "main.h"


struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

static bool cmp_points(const Point& a, const Point& b)
{
	if (a.x > b.x || (a.x == b.x && a.y >= b.y)) return false;
	else return true;
}

int maxPoints(vector<Point>& points) {
	if (points.size() <= 2) return points.size();
	int nb = points.size();
	sort(points.begin(), points.end(), cmp_points);
	int X_min = points[0].x, X_max = points[nb - 1].x;
	int Y_min = INT_MAX, Y_max = INT_MIN;

	int max_count = 2;
	int temp_count = 2;
	int x, y, step_x, step_y;
	int duplicate = 0;

	map<int, int> h;
	h.clear();
	for (int i = 0; i<nb - 1; ++i)
	{
		for (int j = i + 1; j < nb; ++j)
		{
			temp_count = 2 + duplicate;
			step_x = points[j].x - points[i].x;
			step_y = points[j].y - points[i].y;
			if (step_x == 0 && step_y == 0)
			{
				duplicate++;
				continue;
			}
			else
				duplicate = 0;
			/*while(x >= X_min && x <= X_max && y >= Y_min && y <= Y_max)
			{
			if(s.find(pair<int, int>(x, y)) != s.end())
			temp_count++;
			}*/
			for (int k = j + 1; k<nb; ++k)
			{
				if (step_x == 0)
				{
					if (points[k].x == points[j].x)
						temp_count++;
					else break;
				}
				else if (step_y == 0)
				{
					if (points[k].y == points[j].y)
						temp_count++;
				}
				else
				{
					x = points[k].x - points[j].x;
					y = points[k].y - points[j].y;

					if (x * step_y == y * step_x)
						temp_count++;
				}
			}

			if (temp_count > max_count) max_count = temp_count;
		}
		if (temp_count > max_count) max_count = temp_count;
		duplicate = 0;
	}

	return max_count;
}
int maxPoints111(vector<Point>& points) {
	if (points.size() <= 2) return points.size();
	int nb = points.size();
	map<double, int> h;

	int max_count = 2;
	int temp_count = 2;
	int x, y, step_x, step_y;
	int duplicate = 1;
	double scope;
	for (int i = 0; i < nb; ++i)
	{
		for (int j = 0; j < nb; ++j)
		{
			if (i == j) continue;
			if (points[i].x == points[j].x && points[i].y == points[j].y)
			{
				duplicate++;
				continue;
			}
			else if (points[i].x == points[j].x)
				scope = 1000000000.0;
			else
			{
				scope = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
			}
			if (h.count(scope) == 0)
				h.insert(pair<double, int>(scope, 1));
			else
				h[scope]++;
		}
		for (map<double, int>::iterator iter = h.begin(); iter != h.end(); ++iter)
		{
			if (max_count < iter->second + duplicate)
				max_count = iter->second + duplicate;
		}
		if (h.size() == 0)
		{
			max_count = (duplicate > max_count) ? duplicate : max_count;
		}
		duplicate = 1;
		h.clear();
	}

	return max_count;
}
