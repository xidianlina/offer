/*
题目描述:输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	bool HasSubtree(TreeNode *root1, TreeNode *root2)
	{
		if (root1 == NULL || root2 == NULL)
			return false;
		return contains(root1, root2) || contains(root1->left, root2) || contains(root1->right, root2);
	}
	bool contains(TreeNode* root1, TreeNode* root2)
	{
		if (root2 == NULL)
			return true;
		if (root1 == NULL || root1->val != root2->val)
			return false;
		return contains(root1->left, root2->left) && contains(root1->right, root2->right);
	}
};