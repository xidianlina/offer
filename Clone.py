# -*- coding:utf-8 -*-

#��Ŀ����:����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�

# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None
class Solution:
	def Clone(self, head):
		if not head:
			return head
		newHead=RandomListNode(head.label)
		q=newHead
		p=head.next
		dic={head:newHead}
		while p:
			q.next=RandomListNode(p.label)
			dic[p]=q.next
			p=p.next
			q=q.next
		q=newHead
		p=head
		while p:
			if p.random:
				q.random=dic[p.random]
			p=p.next
			q=q.next
		return newHead

	def Clone(self,head):
		if not head:
			return head
		p=RandomListNode(head.label)
		p.next=head.next
		p.random=head.random
		p.next=self.Clone(head.next)
		return p