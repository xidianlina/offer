# -*- coding:utf-8 -*-

'''
题目描述:大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
'''

class Solution:
	def Fibonacci(self, n):
        # write code here
		if n==0:
			return 0
		if n==1:
			return 1
		if n==2:
			return 1
		if n>=3:
			s=[]*n
			s.append(1)
			s.append(1)
			for i in range(2,n):
				s.append(s[i-1]+s[i-2])
			return s[n-1]
	
	def Fibonacci2(self,n=39):
		if n==0:
			return 0
		elif n==1:
			return 1
		f0,f1=0,1
		for i in range(2,n+1):
			res=f0+f1
			f0=f1
			f1=res
		return res