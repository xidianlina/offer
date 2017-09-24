# -*- coding:utf-8 -*-

#��Ŀ����:����һ�ö��������жϸö������Ƿ���ƽ���������

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
	__is_balanced=True
	def IsBalanced_Solution(self, pRoot):
		self.getDepth(pRoot)
		return self.__is_balanced

	def getDepth(self,root):
		if root==None:
			return 0
		left_depth=self.getDepth(root.left)
		right_depth=self.getDepth(root.right)
		if abs(left_depth-right_depth)>1:
			self.__is_balanced=False
		return left_depth+1 if left_depth>right_depth else right_depth+1
		