# -*- coding:utf-8 -*-

#��Ŀ����:��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
#Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}��
#��ô��Ӧ������ǵ�һ���ظ�������2��

class Solution:
	def duplicate(self, numbers, duplication):
		import collections
		c=collections.Counter(numbers)
		for k,v in c.items():
			if v>1:
				duplication[0]=k
				return True
		return False

	def duplicate(self,numbers,duplication):
		if numbers is None or len(numbers)==0:
			return False
		tmp=[]
		flag=False
		for i in numbers:
			if i in tmp:
				duplication[0]=i
				flag=True
			tmp.append(i)
		return flag