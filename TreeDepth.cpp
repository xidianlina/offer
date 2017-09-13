/*
��Ŀ����:����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·����
�·���ĳ���Ϊ������ȡ�
*/

#include <iostream>
#include <list>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	int TreeDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int depth;
		int curLevelNode = 1;
		int nextLevelNode = 0;
		list<TreeNode*> queue;
		queue.push_back(root);
		while (!queue.empty())
		{
			TreeNode* node = queue.front();
			queue.pop_front();
			curLevelNode--;
			if (node->left)
			{
				queue.push_back(node->left);
				nextLevelNode++;
			}
			if (node->right)
			{
				queue.push_back(node->right);
				nextLevelNode++;
			}
			if (curLevelNode == 0)
			{
				depth++;
				curLevelNode = nextLevelNode;
				nextLevelNode = 0;
			}
		}
		return depth;
	}
};