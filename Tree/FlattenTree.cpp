/*---------------leetcode-----------------
---------------Flatten Tree---------------
----------------storm Han-----------------
----------------2016.05.16----------------

Question describing:
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

	1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1
 \
  2
   \
	3
	 \
	  4
	   \
		5
		 \
		  6

*/

#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void flatten(TreeNode* root) {
	if (root->left == NULL && root->right == NULL) return;

	if (root->left != NULL) flatten(root->left);
	if (root->right != NULL) flatten(root->right);

	TreeNode* p = root->right;
	TreeNode* temp = root->left;

	if (temp != NULL)
	{
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		root->right = root->left;
		temp->right = p;
	}
}


void flatten1(TreeNode *root) {
	if (root == NULL) return;
	while (root){
		if (root->left){
			TreeNode *pre = root->left;
			while (pre->right)
				pre = pre->right;
			pre->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		root = root->right;
	}