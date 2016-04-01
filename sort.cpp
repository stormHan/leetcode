#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> a)
{
	for (vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
	{
		cout << *iter << " ";
	}
}

vector<int> insertSorting(vector<int> a)
{
	int length = a.size();
	for (int i = 1; i < length; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			int j = i;
			while (j > 0 && a[j - 1] > temp)
			{
				a[j] = a[j - 1];
				j--;
			}
			a[j] = temp;
		}
	}

	return a;
}

void quickSorting(vector<int> &a, int left, int right)
{
	if (left >= right)
		return 0;
	int key = a[left];
	int low = left;
	int high = right;

	while (low < high)
	{
		while (low < high && key <= a[high])
		{
			high--;
		}
		if (low < high)
			a[low++] = a[high];
		while (low < high && key >= a[low])
		{
			low++;
		}
		if (low < high)
			a[high--] = a[low];
	}
	a[low] = key;
	quickSorting(a, left, low - 1);
	quickSorting(a, low + 1, right);

}

int main()
{
	vector<int>  sortArray = {4, 1, 6, 12, 7, 2, 4};
	int length = sortArray.size();
	//sortArray = insertSorting(sortArray);
	quickSorting(sortArray, 0, length - 1);

	print(sortArray);

	system("pause");
	return 0;	
}