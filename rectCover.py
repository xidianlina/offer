# -*- coding:utf-8 -*-

'''
��Ŀ����
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
'''

class Solution:
	dic={0:0,1:1,2:2}
	def rectCover(self, number):
		# write code here
		if self.dic.get(number)!=None:
			return self.dic[number]
		m1=self.rectCover(number-1)
		self.dic[number-1]=m1
		m2=self.rectCover(number-2)
		self.dic[number-2]=m2
		return m1+m2

	def rectCover(self, number):
		# write code here
		if number==0:
			return 0
		if number==1:
			return 1
		a,b=1,1
		while number>1:
			a,b=b,a+b
			number-=1
		return b