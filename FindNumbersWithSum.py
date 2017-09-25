# -*- coding:utf-8 -*-

#题目描述:输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

class Solution:
	def FindNumbersWithSum(self, array, tsum):
		length=len(array)
		res=[]
		if length<2:
			return res
		left=0
		right=length-1
		while left<right:
			curSum=array[left]+array[right]
			if curSum==tsum:
				res.append(array[left])
				res.append(array[right])
				break
			elif curSum>tsum:
				right-=1
			else:
				left+=1
		return res

	def FindNumbersWithSum(self,array,tsum):
		ls=[]
		if not isinstance(array,list):
			return ls
		for key,val in enumerate(array):
			for v1 in array[key:]:
				if (val+v1)==tsum:
					ls.append([val,v1])
		if ls:
			return ls[0]
		else:
			return ls