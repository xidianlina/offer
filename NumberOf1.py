# -*- coding:utf-8 -*-

#��Ŀ����:����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

class Solution:
	def NumberOf1(self, n):
		# write code here
		return sum([(n>>i&1) for i in range(0,32)])
	
	def NumberOf1(self,n):
		res=0
		if n<0:
			n=n&0xFFFFFFFF
		return bin(n).count('1')
		while n:
			n&=(n-1)
			res+=1
		return res

	def NumberOf1(self,n):
		if n>=0:
			return len([x for x in bin(n)[2:] if x=='1'])
		else:
			return 32-len([x for x in bin(~n)[2:] if x=='1'])

	def NumberOf1(self,n):
		flag=1
		cnt=0
		for i in range(32):
			if n&flag:
				cnt+=1
			flag<<=1
		return cnt