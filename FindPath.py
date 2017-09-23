# -*- coding:utf-8 -*-

#��Ŀ����:����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
	def FindPath(self, root, expectNumber):
		if not root:
			return []
		if root and not root.left and not root.right and root.val == expectNumber:
			return [[root.val]]
		res=[]
		left=self.FindPath(root.left,expectNumber-root.val)
		right=self.FindPath(root.right,expectNumber-root.val)
		for i in left+right:
			res.append([root.val]+i)
		return res