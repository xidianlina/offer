/*
题目描述:输入一个链表，输出该链表中倒数第k个结点。
*/

#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k < 0)
			return NULL;
		ListNode *pFirst = pListHead;
		ListNode *pBehind = NULL;
		for (int i = 0; i < k - 1; i++)
			if (pFirst->next != NULL)
				pFirst = pFirst->next;
			else
				return NULL;
		pBehind = pListHead;
		while (pFirst->next != NULL) {
			pFirst = pFirst->next;
			pBehind = pBehind->next;
		}
		return pBehind;
	}
};