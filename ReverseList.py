# -*- coding:utf-8 -*-

#题目描述:输入一个链表，反转链表后，输出链表的所有元素。

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
	def ReverseList(self, pHead):
		if pHead==None:
			return
		pre=None
		next=None
		while pHead:
			next=pHead.next
			pHead.next=pre
			pre=pHead
			pHead=next
		return pre