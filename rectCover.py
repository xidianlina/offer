# -*- coding:utf-8 -*-

'''
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
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