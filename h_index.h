
/*---------------leetcode-----------------
---------------Level : Mudium-------------
------------------h Index-----------------
----------------storm Han-----------------
----------------2016.03.15----------------

Question describing:

	According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each,

and the other N − h papers have no more than h citations each."

	For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. 

Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

*/

#include <vector>

using namespace std;

int quickSorting(vector<int> &a, int left, int right)
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

	return 0;
}

int hIndex(vector<int>& citations)
{
	int index = 1;
	
	if (citations.size() == 0 || citations.size() == 1)
		return citations.size();

	quickSorting(citations, 0, citations.size() - 1);
	
	for (int i = citations.size() - 1; i >= 0; i--)
	{
		if (index <= citations[i])
			index++;
		else
		{
			return index - 1;
		}
	}
	return index - 1;

}