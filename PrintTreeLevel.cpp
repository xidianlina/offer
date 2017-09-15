/*
题目描述:从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

#include <iostream>
#include <vector>
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
	vector<vector<int> > Print(TreeNode* root) {
		vector<vector<int>> res;
		if (NULL == root)
			return res;
		queue<TreeNode*> que;
		que.push(root);
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
			res.push_back(vec);
		}
		return res;
	}
};