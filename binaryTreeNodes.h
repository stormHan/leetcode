/*---------------leetcode-----------------
---------------Level : Mudium-------------
-------------count b tree nodes-----------
----------------storm Han-----------------
----------------2016.03.15----------------
*/

#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//用对二叉树进行遍历的方式 果然超时了
//int  bianli(TreeNode* a, int* count)
//{
// if (a == NULL)
// {
//	 return 0;
// }
// *count++;
// bianli(a->left, count);
// bianli(a->right, count);

// return 0;
//}

//int countNode(TreeNode* root)
//{
// int count = 0;
// if (root == NULL) return 0;

// bianli(root, &count);

// return count;
//}

//经过我的改善，还是超时
#pragma once

#include <math.h>
int countNodesss___(TreeNode* root)
{
	int count = 0;
	if (root == NULL) return 0;

	int height = 1;
	TreeNode* p = root, *q = root;
	while (p->left != NULL)
	{
		height++;
		p = p->left;
	}

	if (height == 1) return 1;
	count = pow((float)2, (int)(height - 2));
	if (height == 2)
	{
		if (root->left != NULL) count++;
		if (root->right != NULL) count++;

		return count;
	}
	int temp = count;
	for (int i = 0; i < temp; i++)
	{
		int m = i;
		q = root;
		for (int j = 0; j < height - 2; j++)
		{
			if (i % 2 == 0) q = q->left;
			else
			{
				q = q->right;
			}

			m = m >> 1;
			if (q->left != NULL) count++;
			if (q->right != NULL) count++;
		}
	}
	return count;

}


int getLeft__(TreeNode* root){
	int a = 0;
	while (root->left != NULL)
	{
		root = root->left;
		a++;
	}
	return a;
}
int getRight__(TreeNode* root){
	int a = 0;
	while (root->right != NULL)
	{
		root = root->right;
		a++;
	}
	return a;
}

 int countNodes__(TreeNode* root) {
	if (root == NULL) return 0;

	int l = getLeft__(root) + 1;
	int r = getRight__(root) + 1;

	if (l == r){
		return pow((float)2, l) - 1;
	}
	else{
		return countNodes__(root->left) + countNodes__(root->right) + 1;
	}


}