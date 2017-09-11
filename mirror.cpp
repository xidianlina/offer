/*
题目描述:操作给定的二叉树，将其变换为源二叉树的镜像。
*/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	void Mirror(TreeNode* pRoot)
	{
		if (pRoot == NULL) {
			return;
		}
		TreeNode *tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
	void mirror(TreeNode *node)
	{
		if (node == NULL)
			return;
		stack<TreeNode*> stack;
		stack.push(node);
		while (stack.size())
		{
			TreeNode* tree = stack.top();
			stack.pop();
			if (tree->left||tree->right) {
				TreeNode* tmp = tree->left;
				tree->left = tree->right;
				tree->right = tmp;
			}
			if (tree->left)
				stack.push(tree->left);
			if (tree->right)
				stack.push(tree->right);
		}
	}
};