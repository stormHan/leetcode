#include "main.h"

/*
 * \brief Traverses the binary tree in post-order.
 * Iterative:
 */

vector<int> post_order_traversal(TreeNode* root){
	vector<int> result;

	stack<TreeNode*> stk;
	stk.push(root);

	while (!stk.empty()){
		TreeNode* cur = stk.top();

		if (!cur){
			stk.pop();
			continue;
		}

		if (!cur->left && !cur->right){
			stk.pop();
			result.push_back(cur->val);
			continue;
		}

		//pay attention to the order of left and right.
		//we must manipulate the right first to keep the post order.
		if (cur->right){
			stk.push(cur->right);
			cur->right = NULL;
		}

		if (cur->left){
			stk.push(cur->left);
			cur->left = NULL;
		}

	}
	return result;
}

/*
* \brief Traverses the binary tree in in-order.
* Iterative:
*/

// my algo 1
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;

	stack<TreeNode *>stk;
	stk.push(root);

	while (!stk.empty()){
		TreeNode *cur = stk.top();
		stk.pop();
		if (!cur){
			continue;
		}
		if (!cur->left){
			result.push_back(cur->val);
		}
		if (cur->right){
			stk.push(cur->right);
			cur->right = NULL;
		}
		if (cur->left){
			stk.push(cur);
			stk.push(cur->left);
			cur->left = NULL;
		}
	}
	return result;
}

// a cooler algo
vector<int> inorderTraversal(TreeNode *root) {
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
	stack<TreeNode*> S;
	vector<int> ret;
	ret.clear();
	if (root == NULL)
		return ret;
	TreeNode *p = root;
	while (!S.empty() || p)
	{
		if (p != NULL)
		{
			S.push(p);
			p = p->left;
		}
		else{
			p = S.top();
			S.pop();
			ret.push_back(p->val);
			p = p->right;
		}
	}
	return ret;
}