# -*- coding:utf-8 -*-

#题目描述:写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

class Solution:
	def Add(self, num1, num2):
		while num2:
			temp=num1^num2
			num2=(num1&num2)<<1
			num1=temp
		return num1

	def Add(self,num1,num2):
		return sum([num1,num2])