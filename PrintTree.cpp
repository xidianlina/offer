/*
��Ŀ����:��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
	vector<vector<int> > Print(TreeNode* root) {
		vector<vector<int>> res;
		if (NULL == root)
			return res;
		queue<TreeNode*> que;
		que.push(root);
		bool even = false;
		while (!que.empty())
		{
			vector<int> vec;
			const int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* tmp = que.front();
				que.pop();
				vec.push_back(tmp->val);
				if (tmp->left != NULL)
					que.push(tmp->left);
				if (tmp->right != NULL)
					que.push(tmp->right);
			}
			if (even)
				reverse(vec.begin(), vec.end());
			even = !even;
			res.push_back(vec);
		}
		return res;
	}
};