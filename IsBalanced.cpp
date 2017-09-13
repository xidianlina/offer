/*
��Ŀ����:����һ�ö��������жϸö������Ƿ���ƽ���������
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	bool isBalanced = true;
	bool isBalanced(TreeNode* root)
	{
		getDepth(root);
		return isBalanced;
	}
	int getDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left = getDepth(root->left);
		int right = getDepth(root->right);
		if (abs(left - right) > 1)
			isBalanced = false;
		return max(left, right) + 1;
	}
};