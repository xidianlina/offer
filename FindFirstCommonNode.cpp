/*
题目描述:输入两个链表，找出它们的第一个公共结点。
*/

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	//function first
	ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2) {
		unsigned int len1 = GetListLength(head1);
		unsigned int len2 = GetListLength(head2);
		int difLen = len1 - len2;
		ListNode* longList = head1;
		ListNode* shortList = head2;
		if (len2 > len1)
		{
			difLen = len2 - len1;
			longList = head2;
			shortList = head1;
		}
		for (int i = 0; i < difLen; i++)
			longList = longList->next;
		while (longList&&shortList&&longList != shortList)
		{
			longList = longList->next;
			shortList = shortList->next;
		}
		return longList;
	}
	int GetListLength(ListNode* list)
	{
		unsigned int len = 0;
		ListNode* head = list;
		while (head)
		{
			len++;
			head = head->next;
		}
		return len;
	}

	//function second
	ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2)
	{
		if (head1 == NULL || head2 == NULL)
			return NULL;
		stack<ListNode*> stack1;
		stack<ListNode*> stack2;
		while (head1)
		{
			stack1.push(head1);
			head1 = head1->next;
		}
		while (head2)
		{
			stack2.push(head2);
			head2 = head2->next;
		}
		ListNode* common = NULL;
		while (!stack1.empty() && !stack2.empty() && stack1.top() == stack2.top())
		{
			stack1.pop();
			common = stack2.top();
			stack2.pop();
		}
		return common;
	}
};