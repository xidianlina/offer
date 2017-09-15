/*
��Ŀ����:��ʵ�������������ֱ��������л��ͷ����л�������
*/

#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	char* Serialize(TreeNode *root)//���л�,�� �� ���л�Ϊ�ַ���
	{
		if (root == nullptr)
			return "#";
		string str = to_string(root->val);
		str.push_back(',');
		char* left = Serialize(root->left);
		char* right = Serialize(root->right);
		char* temp = new char[str.size() + strlen(left) + strlen(right)];//���ݺ��������������������С
		strcpy(temp, str.c_str());//c_str() �� char* ��ʽ���� string ����ַ�
		strcat(temp, left);
		strcat(temp, right);
		return temp;
	}
	TreeNode* Deserialize(char* &str)//�����л���Ҫ�����ò���Ч����ΪҪһֱ��¼ strָ�� ���ƵĹ���
	{
		if (*str == '#')
		{
			str++;
			return nullptr;
		}
		int num = 0;
		while (*str != ',')//��Щ������һλ�������
			num = num * 10 + (*(str++) - '0');
		str++;//��������
		TreeNode *root = new TreeNode(num);//�½��ڵ�ĳ�ʼ����ֵΪ֮ǰ���num
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}
};