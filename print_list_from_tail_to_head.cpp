///*
//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
//*/
//
//#include <iostream>
//#include <vector>
//#include <stack>
//
//using std::vector;
//using std::stack;
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x):val(x),next(NULL){}
//};
//
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		vector<int> result;
//		if (head == NULL) {
//			return result;
//		}
//		stack<ListNode*> reverse;
//		ListNode* node = head;
//		while (node != NULL) {
//			reverse.push(node);
//			node = node->next;
//		}
//		while (!reverse.empty()) {
//			node = reverse.top();
//			result.push_back(node->val);
//			reverse.pop();
//		}
//
//		return result;
//	}
//};