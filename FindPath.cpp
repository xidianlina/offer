/*
��Ŀ����:����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {	
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		vector<vector<int> > FindPath;
		vector<int> Path;  // Ϊ�˱���ÿһ�εݹ��ֵ,����������һ��path
		if (root == NULL)
			return FindPath;
		TreePath(root, expectNumber, Path, FindPath);
		return FindPath;
	}

	void TreePath(TreeNode* root, int target, vector<int> &path, vector<vector<int> > &pathList)
	{
		if (root == NULL)
			return;
		path.push_back(root->val);
		if (root->val == target && root->left == NULL && root->right == NULL)
		{
			pathList.push_back(path);
			path.pop_back();
		}
		else
		{
			TreePath(root->left, target - root->val, path, pathList);
			TreePath(root->right, target - root->val, path, pathList);
			path.pop_back();
		}
	}
};