# -*- coding:utf-8 -*-

#��Ŀ����:����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�

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