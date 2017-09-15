/*
题目描述:请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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