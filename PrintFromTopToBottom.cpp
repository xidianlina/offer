/*
题目描述:从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode *root)
	{
		deque<TreeNode*> deque;
		vector<int> res;
		if (root == NULL)
			return res;
		deque.push_back(root);
		while (!deque.empty())
		{
			res.push_back(deque.front()->val);
			if (deque.front()->left != NULL)
				deque.push_back(deque.front()->left);
			if (deque.front()->right != NULL)
				deque.push_back(deque.front()->right);
			deque.pop_front();
		}
		return res;
	}
};