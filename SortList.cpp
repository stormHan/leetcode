/*---------------leetcode-----------------
-----------------Sort List----------------
----------------storm Han-----------------
----------------2016.03.13----------------

Question describing:
Sort a linked list in O(n log n) time using constant space complexity.

*/

#include <stdio.h>


	//Definition for singly-linked list
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){ }
		
};


class  Solution
{
public:
	//快速排序，小的数据往前排，大的数据往后排
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return NULL;
		}

		ListNode* p = head->next;
		ListNode* p_pre = p;
		bool flag = false;		//用于标记是否有交换，当数组有序的时候，提高判断效率

		while (p_pre->next != NULL)
		{
			p = p->next;
			int temp = p_pre->val;
			
			while (p)
			{
				if (temp < (p->val))
				{
					p = p->next;
					continue;
				}
				else
				{
					int temp_change;
					temp_change = p->val;
					p->val = p_pre->val;
					p_pre->val = temp_change;
					p = p->next;
					flag = true;
				}
				if (flag == false)
					return head;
			}
			p_pre = p_pre->next;
			p = p_pre;
		}
		return head;
	}

	//符合要求的是归并排序，快速排序：使用快排也行，就是每次利用头节点作为基准，
	//将小于它的交换到链表左侧，大于它的放在右侧，最后把它换到中间某个位置，然后递归处理左侧和右侧。
	//	但是相对于归并来说，它的元素交换次数太多了，可能会超时。

	ListNode* merge(ListNode *lh, ListNode *rh)
	{
		ListNode *temp = new ListNode(0);
		ListNode *p = temp;

		while (lh && rh)
		{
			if (lh->val <= rh->val){
				p->next = lh;
				lh = lh->next;
			}
			else
			{
				p->next = rh;
				rh = rh->next;
			}
			p = p->next;

			if (!lh)
				p->next = rh;
			if (!rh)
				p->next = lh;
		}
		p = temp->next;
		temp->next = NULL;
		delete temp;
		return p;
	}

	ListNode* mergeSort(ListNode *head)
	{
		if (!head || !head->next)
			return head;

		ListNode *p = head, *q = head, *pre = NULL;

		while (q && q->next != NULL)
		{
			q = q->next->next;
			pre = p;
			p = p->next; //divide into two part
		}

		pre->next = NULL;
		ListNode *lhalf = mergeSort(head);
		ListNode *rhalf = mergeSort(p);
		return merge(lhalf, rhalf);
	}

	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return head;
		
		ListNode* p = head->next;
		ListNode* p_pre = head;

		while (p != NULL)
		{

		}
		
	}

	void deleteNode(ListNode* node) {
		ListNode* p, *q;
		if (node != NULL)
		{
			p = node->next;
			if (p != NULL)
			{
				q = p->next;
				node->val = p->val;
				node->next = q;
			}
			else
			{
				node = NULL;
			}
		}

	}

    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)return head;
        if (head->next == NULL) return head;

        ListNode *p = head, *q = head->next;
        ListNode *store = head->next;

        while (q != NULL)
        {
            p->next = q->next;
            if (p->next != NULL)
            {
                q->next = p->next->next;

                p = p->next;
                q = q->next;
            }
            else
            {
                break;
            }
        }
        p->next = store;
        return head;
    }
}; 