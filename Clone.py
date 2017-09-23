# -*- coding:utf-8 -*-

#题目描述:输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

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