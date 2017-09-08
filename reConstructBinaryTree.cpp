///*
//题目描述:输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
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