/*
��Ŀ����:��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻������
��������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/

#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {}
};

class Solution {
public:
	//function first
	ListNode* deleteDuplication(ListNode* head)
	{
		if (head == NULL)
			return NULL;
		if (head != NULL&&head->next == NULL)
			return head;
		ListNode* cur;
		if (head->val == head->next->val)
		{
			cur = head->next->next;
			while (cur != NULL&&cur->val == head->val)
				cur = cur->next;
			return deleteDuplication(cur);
		}
		else {
			cur = head->next;
			head->next = deleteDuplication(cur);
			return head;
		}
	}

	//function second
	ListNode* deleteDuplication(ListNode* head)
	{
		ListNode first = new ListNode(-1);
		first->next = head;
		ListNode *p = head;
		ListNode *last = first;
		while (p != NULL&&p->next != NULL)
		{
			if (p->val == p->next->val)
			{
				int val = p->val;
				while (p != NULL&&p->val == val)
					p = p->next;
				last->next = p;
			}
			else {
				last = p;
				p = p->next;
			}
		}
		return first->next;
	}
};