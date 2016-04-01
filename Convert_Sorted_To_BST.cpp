/*---------------leetcode-----------------
------------Depth fisrt Search-----------
----------------storm Han-----------------
----------------2016.03.04----------------

Question describing:
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/
#include <stdio.h>

// Definition for singly-linked list.
struct  ListNode
{
	int val;
	ListNode* next;

	ListNode(int x) :val(x), next(NULL) {};
};

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution{
public :
	TreeNode* sortedListToBST(ListNode* head){
		if (head == NULL)
			return NULL;
		ListNode* List_Mid = head, *preMid = NULL, *tail = head->next;

		while (tail){
			tail = tail->next;
			if (tail) tail = tail->next;

			preMid = List_Mid;
			List_Mid = List_Mid->next;
		}

		TreeNode *cur = new TreeNode(List_Mid->val);
		
		if (preMid == NULL) cur->left = NULL;
		else
		{
			preMid->next = NULL;
			cur->left = sortedListToBST(head);
		}
		cur->right = sortedListToBST(List_Mid->next);
	
		return cur;
	}
};