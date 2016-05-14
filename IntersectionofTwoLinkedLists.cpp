/*---------------leetcode-----------------
---------------Level : Easy---------------
----Intersection of Two LinkedLists-------
----------------storm Han-----------------
----------------2016.05.14----------------

Question describing:
For example, the following two linked lists:

A:          a1 ¡ú a2
					¨K
					c1 ¡ú c2 ¡ú c3
					¨J
B:     b1 ¡ú b2 ¡ú b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
#include <stdio.h>


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
	int lenA = 0, lenB = 0;
	bool flag = true;

	ListNode* p = headA;
	ListNode* q = headB;
	while (p != NULL)
	{
		p = p->next;
		lenA++;
	}

	p = headB;
	while (p != NULL)
	{
		p = p->next;
		lenB++;
	}
	p = headA;

	int intern = (lenA > lenB) ? (lenA - lenB) : (lenB - lenA);

	if (lenA > lenB)
	{
		while (intern > 0)
		{
			p = p->next;
			intern--;
		}
	}
	else
	{
		while (intern > 0)
		{
			q = q->next;
			intern--;
		}
	}

	while (q != NULL && p != NULL)
	{
		if (p == q) return p;

		p = p->next;
		q = q->next;
	}

	return NULL;
}