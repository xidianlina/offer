# -*- coding:utf-8 -*-

#��Ŀ����:��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��

class Solution:
	def FirstNotRepeatingChar(self, s):
		if not s:
			return -1
		for i,ch in enumerate(s):
			if s.count(ch)==1:
				return i

	def FirstNotRepeatingChar(self,s):
		index=0
		if len(s)==0:
			return -1
		else:
			for x in s:
				if s.count(x)==1:
					return index
				index+=1