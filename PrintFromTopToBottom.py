# -*- coding:utf-8 -*-

#题目描述:从上往下打印出二叉树的每个节点，同层节点从左至右打印。

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
	def PrintFromTopToBottom(self, root):
		l=[]
		if not root:
			return []
		q=[root]
		while len(q):
			t=q.pop(0)
			l.append(t.val)
			if t.left:
				q.append(t.left)
			if t.right:
				q.append(t.right)
		return l