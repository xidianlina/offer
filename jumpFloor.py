# -*- coding:utf-8 -*-

'''
题目描述:一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
'''

class Solution:
    def jumpFloor(self, number):
        # write code here
		a=1
		b=1
		for i in range(number):
			a,b=b,a+b
		return a

	def jumpFloor(self,number):
		if number<=0:
			return 1
		elif number<=2:
			return number
		else:
			a,b=1,2
			for i in range(2,number):
				a,b=b,a+b
			return b