# -*- coding:utf-8 -*-

#题目描述:输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
	def TreeDepth(self, root):
		if root is None:
			return 0
		from collections import deque
		dq=deque()
		layer=1
		dq.append((root,1))
		while dq:
			node,layer=dq.popleft()
			deep=layer
			if node.left:
				dq.append((node.left,layer+1))
			if node.right:
				dq.append((node.right,layer+1))
		return deep

	def TreeDepth(self,root):
		if not root:
			return 0
		a=[root]
		d=0
		while a:
			b=[]
			for node in a:
				if node.left:
					b.append(node.left)
				if node.right:
					b.append(node.right)
			a=b
			d=d+1
		return d