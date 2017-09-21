# -*- coding:utf-8 -*-

'''
��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
'''

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # ���ع����TreeNode���ڵ�
    def reConstructBinaryTree(self, pre, tin):
        # write code here
		if len(pre)==0:
			return None
		if len(pre)==1:
			return TreeNode(pre[0])
		else:
			tree=TreeNode(pre[0])
			tree.left=self.reConstructBinaryTree(pre[1:tin.index(pre[0])+1],tin[:tin.index(pre[0])])
			tree.right=self.reConstructBinaryTree(pre[tin.index(pre[0])+1:],tin[tin.index(pre[0])+1:])
		return tree

    def reConstructBinaryTree2(self, pre, tin):
        if not pre:
            return None
        root=TreeNode(pre[0])
        pos=tin.index(pre[0])
        root.left=self.reConstructBinaryTree(pre[1:pos+1],tin[0:pos])
        root.right=self.reConstructBinaryTree(pre[pos+1:],tin[pos+1:])
        return root