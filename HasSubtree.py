# -*- coding:utf-8 -*-

'''
��Ŀ����:�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
'''

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
	def HasSubtree(self, root1, root2):
		if root1==None or root2==None:
			return False
		return self.containTree(root1,root2) or self.containTree(root1.left,root2) or self.containTree(root1.right,root2)

	def containTree(self,root1,root2):
		if root2==None:
			return True
		if root1==None or root1.val!=root2.val:
			return False
		return self.containTree(root1.left,root2.left) and self.containTree(root1.right,root2.right)