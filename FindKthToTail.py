# -*- coding:utf-8 -*-

#��Ŀ����:����һ����������������е�����k����㡣

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
	def FindKthToTail(self, head, k):
		if head==None or k<1:
			return None
		pfirst=head
		pbehind=None
		for i in range(0,k-1):
			if pfirst.next!=None:
				pfirst=pfirst.next
			else:
				return None
		pbehind=head
		while pfirst.next!=None:
			pfirst=pfirst.next
			pbehind=pbehind.next
		return pbehind

	def FindKthToTail(self,head,k):
		l=[]
		while head!=None:
			l.append(head);
			head=head.next
		if k>len(l) or k<1:
			return 
		return l[-k]