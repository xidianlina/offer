# -*- coding:utf-8 -*-

'''
��Ŀ����:����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
'''

class Solution:
	def __init__(self):
		self.stk=[]
		self.min_stack=[]
'''
	def push(self,node):
		self.stk.append(node)
		if not self.min_stack or node<=self.min_stack[-1]:
			self.min_stack.append(node)

	def pop(self):
		if self.stk[-1]==self.min_stack[-1]:
			self.min_stack.pop()
		self.stk.pop()

	def top(self):
		return self.stk[-1]

	def min(self):
		return self.min_stack[-1]
'''

	def push(self,node):
		self.stk.append(node)
		if not self.min_stack or node<=self.min_stack[-1]:
			self.min_stack.append(node)
		else:
			self.min_stack.append(self.min_stack[-1])
		
	def pop(self):
		self.stk.pop()
		self.min_stack.pop()
	
	def top(self):
		return self.stk[-1]

	def min(self):
		return self.min_stack[-1]