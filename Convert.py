# -*- coding:utf-8 -*-

#��Ŀ����:����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
	def Convert(self, root):
		if (not root) or (not root.left and not root.right):
			return root
		left=self.Convert(root.left)
		node=left
		while node and node.right:
			node=node.right
		if node:
			node.right=root
			root.left=node
		right=self.Convert(root.right)
		if right:
			root.right=right
			right.left=root
		if left:
			return left
		return root