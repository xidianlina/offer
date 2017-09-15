/*
��Ŀ����:����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣
���磬 5 / \ 3 7 /\ /\ 2 4 6 8 �У��������ֵ��С˳�����������ֵΪ4��
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