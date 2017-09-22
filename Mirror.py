# -*- coding:utf-8 -*-

#题目描述:操作给定的二叉树，将其变换为源二叉树的镜像。

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