# -*- coding:utf-8 -*-

#题目描述:输入两个链表，找出它们的第一个公共结点。

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
	def FindFirstCommonNode(self, head1, head2):
		list1=[]
		list2=[]
		node1=head1
		node2=head2
		while node1:
			list1.append(node1.val)
			node1=node1.next
		while node2:
			if node2.val in list1:
				return node2
			else:
				node2=node2.next

	def FindFirstCommonNode(self,head1,head2):
		p1=head1
		p2=head2
		while p1!=p2:
			p1=p1.next if p1!=None else head2
			p2=p2.next if p2!=None else head1
		return p1