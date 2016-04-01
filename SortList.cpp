<<<<<<< HEAD
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
	//��������С��������ǰ�ţ��������������
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return NULL;
		}

		ListNode* p = head->next;
		ListNode* p_pre = p;
		bool flag = false;		//���ڱ���Ƿ��н����������������ʱ������ж�Ч��

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

	//����Ҫ����ǹ鲢���򣬿�������ʹ�ÿ���Ҳ�У�����ÿ������ͷ�ڵ���Ϊ��׼��
	//��С�����Ľ�����������࣬�������ķ����Ҳ࣬�����������м�ĳ��λ�ã�Ȼ��ݹ鴦�������Ҳࡣ
	//	��������ڹ鲢��˵������Ԫ�ؽ�������̫���ˣ����ܻᳬʱ��

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
=======
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
	//��������С��������ǰ�ţ��������������
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return NULL;
		}

		ListNode* p = head->next;
		ListNode* p_pre = p;
		bool flag = false;		//���ڱ���Ƿ��н����������������ʱ������ж�Ч��

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

	//����Ҫ����ǹ鲢���򣬿�������ʹ�ÿ���Ҳ�У�����ÿ������ͷ�ڵ���Ϊ��׼��
	//��С�����Ľ�����������࣬�������ķ����Ҳ࣬�����������м�ĳ��λ�ã�Ȼ��ݹ鴦�������Ҳࡣ
	//	��������ڹ鲢��˵������Ԫ�ؽ�������̫���ˣ����ܻᳬʱ��

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
>>>>>>> 62ecb277e79aab08296e767ad6966f02a9fcf0f1
}; 