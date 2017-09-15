/*
题目描述:请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	//function first
	bool isSymmetrical(TreeNode* root)
	{
		if (root == NULL)
			return true;
		queue<TreeNode*> q1, q2;
		TreeNode*left, *right;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty())
		{
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (NULL == left&&NULL == right)
				continue;
			if (NULL == left || NULL == right)
				return false;
			if (left->val != right->val)
				return false;
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
		return true;
	}

	//function second
	bool isSymmetrical2(TreeNode* root) {
		return isSymmetrical2(root, root);
	}

	bool isSymmetrical2(TreeNode* root1, TreeNode* root2) {
		if (root1 == NULL&&root2 == NULL)
			return true;
		if (root1 == NULL || root2 == NULL)
			return false;
		if (root1->val != root2->val)
			return false;
		return isSymmetrical2(root1->left, root2->right) && isSymmetrical2(root1->right, root2->left);
	}
};