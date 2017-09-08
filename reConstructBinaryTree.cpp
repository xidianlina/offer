///*
//��Ŀ����:����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
//���������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
//*/
//
//#include <iostream>
//#include <vector>
//
//using std::vector;
//
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x):val(x),left(NULL),right(NULL){}
//};
//
//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//		int in_size = vin.size();
//		if (in_size == 0)
//			return NULL;
//		vector<int> pre_left, pre_right, in_left, in_right;
//		int val = pre[0];
//		TreeNode* node = new TreeNode(val);
//		int p = 0;
//		for (p; p < in_size; ++p) {
//			if (vin[p] == val)
//				break;
//		}
//		for (int i = 0; i < in_size; i++) {
//			if (i < p) {
//				in_left.push_back(vin[i]);
//				pre_left.push_back(pre[i + 1]);
//			}
//			else if (i > p) {
//				in_right.push_back(vin[i]);
//				pre_right.push_back(pre[i]);
//			}
//		}
//		node->left = reConstructBinaryTree(pre_left, in_left);
//		node->right = reConstructBinaryTree(pre_right, in_right);
//
//		return node;
//	}
//};