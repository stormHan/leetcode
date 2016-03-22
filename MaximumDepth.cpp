/*---------------leetcode-----------------
---------------Level : Easy---------------
----------Maximum Depth of Binary Tree----
----------------storm Han-----------------
----------------2016.03.22----------------
*/

#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max(int a, int b)
{
	if(a >= b) return a;
	else
	{
		return b;
	}
}

int maxDepth(TreeNode* root)
{
	int maxDp;

	if (root == NULL)
		return 0;
	else
	{
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
}