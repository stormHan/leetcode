/*---------------leetcode-----------------
-------------- Level : Hard --------------
-------Binary Tree Maximum Path Sum-------
----------------storm Han-----------------
----------------2016.11.07----------------
Question describing:
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
The path does not need to go through the root.

For example:
Given the below binary tree,

1
/ \
2   3
Return 6.
*/
#include "main.h"

int _max = INT_MIN;


//注意这种自底向上的递归方法
int find(TreeNode* root)
{
	int sum = 0;
	if (root == NULL) return 0;
	int l = find(root->left);
	int r = find(root->right);

	if (r < 0) r = 0;
	if (l < 0) l = 0;
	if (r > 0) sum += r;
	if (l > 0) sum += l;
	sum = sum + root->val;
	if (sum > _max) _max = sum;
	return max(l, r) + root->val;

}
int maxPathSum(TreeNode* root) {
	find(root);
	return _max;
}