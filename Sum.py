# -*- coding:utf-8 -*-

#��Ŀ����:��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

class Solution:
	def __init__(self):
		self.all_sum=0
	def Sum_Solution(self, n):
		def getsum(n):
			self.all_sum+=n
			n-=1
			return n>0 and self.Sum_Solution(n)
		getsum(n)
		return self.all_sum

	def Sum_Solution(self,n):
		return reduce(lambda x,y:x+y,range(n+1))

	def Sum_Solution(self,n):
		return n and (n+self.Sum_Solution(n-1))