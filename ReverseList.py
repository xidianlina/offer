# -*- coding:utf-8 -*-

#��Ŀ����:����һ��������ת�����������������Ԫ�ء�

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