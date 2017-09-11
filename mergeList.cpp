/*
题目描述:输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode* Merge(ListNode* list1, ListNode* list2)
	{
		if (list1 == NULL)
			return list2;
		else if (list2 == NULL)
			return list1;
		ListNode* head = (list1->val < list2->val) ? list1 : list2;
		ListNode* cur1 = (head == list1) ? list1 : list2;
		ListNode* cur2 = (head == list1) ? list2 : list1;
		ListNode* pre = NULL;
		ListNode* next = NULL;
		while (cur1 != NULL&&cur2 != NULL) 
		{
			if (cur1->val < cur2->val)
			{
				pre = cur1;
				cur1 = cur1->next;
			}
			else 
			{
				next = cur2->next;
				pre->next = cur2;
				cur2->next = cur1;
				pre = cur2;
				cur2 = next;
			}
		}
		pre->next = cur1 == NULL ? cur2 : cur1;
		return head;
	}

	ListNode* merge(ListNode* list1, ListNode* list2)
	{
		if (list1 == NULL)
			return list2;
		else if (list2 == NULL)
			return list1;
		ListNode* head = NULL;
		if (list1->val < list2->val)
		{
			head = list1;
			head->next = merge(list1->next, list2);
		}
		else
		{
			head = list2;
			head->next = merge(list1, list2->next);
		}
		return head;
	}
};