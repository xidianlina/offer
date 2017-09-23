# -*- coding:utf-8 -*-

#题目描述:输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

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