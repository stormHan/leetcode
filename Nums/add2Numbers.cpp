#include <iostream>
#include <vector>
#include <map>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *Lans = new ListNode(0);
		ListNode *hNode = Lans, *hNode2 = Lans;
		bool flag = false;
		int val1, val2;

		do{
			if (flag == true)
			{
				Lans->val++;
				flag = false;
			}

			if (l1 != NULL)
			{
				val1 = l1->val;
				l1 = l1->next;
			}
			else
			{
				val1 = 0;
			}
			if (l2 != NULL)
			{
				val2 = l2->val;
				l2 = l2->next;
			}
			else
			{
				val2 = 0;
			}
			if (val1 + val2 + Lans->val >= 10) flag = true;
			Lans->val = (val1 + val2 + Lans->val) % 10;
			if (l1 != NULL || l2 != NULL || flag)
			{
				ListNode *pNode = new ListNode(0);
				Lans->next = pNode;
				Lans = Lans->next;
			}
		} while (l1 != NULL || l2 != NULL || flag == true);
		for (; hNode != NULL; hNode = hNode->next)
		{
			if (hNode->next != NULL)
				std::cout << hNode->val << "->";
			else
				std::cout << hNode->val;
		}
		return hNode2;
	}
};