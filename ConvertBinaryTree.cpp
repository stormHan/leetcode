/*
-------------LeetCode-----------------
-------------Storm han----------------
-------Binary Tree Recursive----------
------------2016.04.16----------------

Decription:
Invert a binary tree.

4
/   \
2     7
/ \   / \
1   3 6   9
to
4
/   \
7     2
/ \   / \
9   6 3   1

*/

#include <vector>

using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	
	int val;

	TreeNode(int value) : val(value), right(NULL), left(NULL) {};
};

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
	{
		return root;
	}
	else
	{
		TreeNode* newleftNode = invertTree(root->right);
		TreeNode* newrightNode = invertTree(root->left);

		root->left = newleftNode;
		root->right = newrightNode;

		return root;
	}
}

vector<int> preOrder(TreeNode* root)
{
	vector<int> ret;
	if (root == NULL)
	{
		return ret;
	}
	else
	{
		vector<int> leftRecursive;
		vector<int> rightRecursive;

		ret.push_back(root->val);
		leftRecursive = preOrder(root->left);
		rightRecursive = preOrder(root->right);
		
		for (vector<int>::iterator iter = leftRecursive.begin(); iter != leftRecursive.end(); ++iter)
		{
			ret.push_back(*iter);
		}

		for (vector<int>::iterator iter = rightRecursive.begin(); iter != rightRecursive.end(); ++iter)
		{
			ret.push_back(*iter);
		}

		return ret;
	}

}

bool isFisrtRucursive = true;

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> ret;
	if (root == NULL) return ret;

		string temp;
		char t[256];
		sprintf(t, "%d", root->val);
		if (isFisrtRucursive)
		{
			temp = t;
			isFisrtRucursive = false;
		}
		else
		{
			temp = t;
			temp = "->" + temp;
		}
		vector<string> leftPath = binaryTreePaths(root->left);
		vector<string> rightPath = binaryTreePaths(root->right);

		for (vector<string>::iterator iter = leftPath.begin(); iter != leftPath.end(); ++iter)
		{
			string temp2 = temp;
			temp2 += *iter;
			ret.push_back(temp2);
		}

		for (vector<string>::iterator iter = rightPath.begin(); iter != rightPath.end(); ++iter)
		{
			string temp2 = temp;
			temp2 += *iter;
			ret.push_back(temp2);
		}

		return ret;
	
}