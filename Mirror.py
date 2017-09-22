# -*- coding:utf-8 -*-

#��Ŀ����:���������Ķ�����������任ΪԴ�������ľ���

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
	def Mirror(self,root):
		if root!=None:
			root.left,root.right=root.right,root.left
			self.Mirror(root.left)
			self.Mirror(root.right)
	
	def Mirror(self,root):
		stk=[]
		if root is None:
			return root
		else:
			stk.append(root)
			while len(stk)!=0:
				p=stk.pop()
				p.left,p.right=p.right,p.left

				if p.left:
					stk.append(p.left)
				if p.right:
					stk.append(p.right)