/*
题目描述:给定一颗二叉搜索树，请找出其中的第k大的结点。
例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
*/

#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	TreeNode* KthNode(TreeNode* root, int k)
	{
		if (root == NULL||k<=0)
			return NULL;
		stack<TreeNode*> s;
		TreeNode *p = root;
		while (p || !s.empty())
			if (p)
			{
				s.push(p);
				p = p->left;
			}
			else
			{
				p = s.top();
				if (k == 1)
					return p;
				k--;
				s.pop();
				p = p->right;
			}
		return NULL;
	}
};