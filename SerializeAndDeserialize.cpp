/*
题目描述:请实现两个函数，分别用来序列化和反序列化二叉树
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
	char* Serialize(TreeNode *root)//序列化,把 树 序列化为字符串
	{
		if (root == nullptr)
			return "#";
		string str = to_string(root->val);
		str.push_back(',');
		char* left = Serialize(root->left);
		char* right = Serialize(root->right);
		char* temp = new char[str.size() + strlen(left) + strlen(right)];//根据后面三步所需申请数组大小
		strcpy(temp, str.c_str());//c_str() 以 char* 形式传回 string 里的字符
		strcat(temp, left);
		strcat(temp, right);
		return temp;
	}
	TreeNode* Deserialize(char* &str)//反序列化，要传引用才有效，因为要一直记录 str指针 后移的过程
	{
		if (*str == '#')
		{
			str++;
			return nullptr;
		}
		int num = 0;
		while (*str != ',')//有些数不是一位数的情况
			num = num * 10 + (*(str++) - '0');
		str++;//跳过逗号
		TreeNode *root = new TreeNode(num);//新建节点的初始化的值为之前求的num
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}
};