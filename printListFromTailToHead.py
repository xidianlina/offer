#题目描述:输入一个链表，从尾到头打印链表每个节点的值。

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
 
class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        head = listNode
        while head:
            l.insert(0, head.val)
            head = head.next
        return l

	def printListFromTailToHead2(self,listNode):
		l=list()
		while listNode:
			l.append(listNode.val)
			listNode=listNode.next
		return l[::-1]

	def printListFromTailToHead3(self,listNode):
		if not listNode:
			return []
		temp=deque()
		while listNode:
			temp.appendleft(listNode.val)
			listNode=listNode.next
		return temp

	def printListFromTailToHead4(self, listNode):
		# write code here
		lis = []
		while   listNode:
			lis.append(listNode.val)
			listNode = listNode.next
		lis.reverse()
		return  lis
    def printListFromTailToHead5(self, listNode):
        # write code here
        if listNode == None:
            return []
        return self.printListFromTailToHead(listNode.next) + [listNode.val]