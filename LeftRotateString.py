# -*- coding:utf-8 -*-

#��Ŀ����:����һ���������ַ�����S���������ѭ������Kλ������������
#���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����

class Solution:
	def LeftRotateString(self, s, n):
		return s[n:]+s[:n]