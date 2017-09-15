/*
��Ŀ����:����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*/

#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode* left = NULL;
	struct TreeLinkNode* right = NULL;
	struct TreeLinkNode* next = NULL;
	TreeLinkNode(int x):val(x){}
};

class Solution {
public:
	/*
	��������������һ���ڵ㣬һ�������������
	1.������Ϊ�գ��򷵻ؿգ�
	2.�ڵ��Һ��Ӵ��ڣ�������һ��ָ��Ӹýڵ���Һ��ӳ�����һֱ����ָ�����ӽ���ָ���ҵ���Ҷ�ӽڵ㼴Ϊ��һ���ڵ㣻
	3.�ڵ㲻�Ǹ��ڵ㡣����ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ㣻����������ϱ����丸�ڵ�ĸ��ڵ㣬�ظ�֮ǰ���жϣ����ؽ����
	*/
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		if (pNode->right != NULL)
		{
			pNode = pNode->right;
			while (pNode->left != NULL)
				pNode = pNode->left;
			return pNode;
		}
		while (pNode->next != NULL)
		{
			TreeLinkNode *root = pNode->next;
			if (root->left == pNode)
				return root;
			pNode = pNode->next;
		}
		return NULL;
	}
};