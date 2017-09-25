# -*- coding:utf-8 -*-

#题目描述:在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
#也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
#那么对应的输出是第一个重复的数字2。

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