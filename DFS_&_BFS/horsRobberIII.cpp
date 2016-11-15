/*---------------leetcode-----------------
---------------Level : Medium-------------
------------- House Robber III  ----------
----------------storm Han-----------------
----------------2016.11.1-----------------
Question describing:
The thief has found himself a new place for his thievery again. There is only one entrance to this area,
called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized 
that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses
were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
3
/ \
2   3
\   \
3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
3
/ \
4   5
/ \   \
1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/*
	notes:
	DFS 往往使用stack和recursion的形式。
	而BFS 则是使用队列、
*/
#include "main.h"

map<TreeNode*, int> hmap;

int rob(TreeNode* root) {
	if (hmap.count(root) != 0) return hmap[root];
	if (!root)
	{
		hmap.insert(pair<TreeNode*, int>(root, 0));
		return 0;
	}
	int val = 0;
	if (root->left)
	{
		val += rob(root->left->left) + rob(root->left->right);
	}
	if (root->right)
	{
		val += rob(root->right->left) + rob(root->right->right);
	}

	int ret = max(val + root->val, rob(root->left) + rob(root->right));
	hmap.insert(pair<TreeNode*, int>(root, ret));

	return ret;
}