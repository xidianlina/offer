/*
��Ŀ����:����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/

#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode* Convert(TreeNode* root)
	{
		if (root == NULL || root->left == NULL&&root->right == NULL)
			return root;
		TreeNode* left = Convert(root->left);
		TreeNode* node = left;
		while (node&&node->right)
			node = node->right;
		if (node)
		{
			node->right = root;
			root->left = node;
		}
		TreeNode* right = Convert(root->right);
		if (right)
		{
			root->right = right;
			right->left = root;
		}
		return left ? left : root;
	}
};