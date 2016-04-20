/*---------------leetcode-----------------
---------------Level : Medium-------------
---------------Detect Circle--------------
----------------storm Han-----------------
----------------2016.04.20----------------

Question describing:
Find a LinkLIst's beginning of a circle'
if not a circle, return NULL

*/

#include <map>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head)
{
	map<ListNode*, int> hmap;
	ListNode* p = head;
	if (p == NULL) return NULL;
	while (p->next != NULL)
	{
		if (hmap.count(p) != 1)
		{
			return p;
		}
		else
		{
			hmap.insert(pair<ListNode*, int>(p, 1));
		}

		p = p->next;
	}

	return NULL;
}