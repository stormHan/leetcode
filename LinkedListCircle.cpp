/*---------------leetcode-----------------
------------Linked List Circle------------
----------------storm Han-----------------
----------------2016.04.03----------------

Question describing:

Given a linked list, determine if it has a cycle in it.

Follow up:

Can you solve it without using extra space?

*/
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

bool hasCycle(ListNode *head) {
	if (head == NULL) return false;

	ListNode* p = head;

	if (p->next == NULL) return false;

	ListNode* q = p->next;

	for (; p != q; p = p->next)
	{
		if (q == NULL) return false;
		q = q->next;

		if (q == NULL) return false;
		q = q->next;
	}

	return true;
}