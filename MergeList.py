# -*- coding:utf-8 -*-

'''
��Ŀ����:���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
'''

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
	def Merge(self, pHead1, pHead2):
		mergeHead=ListNode(-1)
		p=mergeHead
		while pHead1 and pHead2:
			if pHead1.val>=pHead2.val:
				mergeHead.next=pHead2
				pHead2=pHead2.next
			else:
				mergeHead.next=pHead1
				pHead1=pHead1.next
			mergeHead=mergeHead.next
		if pHead1:
			mergeHead.next=pHead1
		elif pHead2:
			mergeHead.next=pHead2
		return p.next