# -*- coding:utf-8 -*-

#��Ŀ����:����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

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