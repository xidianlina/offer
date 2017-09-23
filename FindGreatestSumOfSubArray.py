# -*- coding:utf-8 -*-

'''
题目描述:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,
问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
'''
class Solution:
	def FindGreatestSumOfSubArray(self, array):
		length=len(array)
		if array is None or length==0:
			return -1

		curSum=array[0]
		maxSum=array[0]
		for i in range(1,length):
			if curSum<=0:
				curSum=array[i]
			else:
				curSum+=array[i]
			if curSum>maxSum:
				maxSum=curSum
		return maxSum

	def FindGreatestSumOfSubArray(self,array):
		if len(array)<=0:
			return []
		temp_sum=0
		list_sum=[]
		for i in array:
			temp_sum=temp_sum+i
			list_sum.append(temp_sum)
			if temp_sum>0:
				continue
			else:
				temp_sum=0
		return max(list_sum)

	def FindGreatestSumOfSubArray(self,array):
		res=max(array)
		temp=0
		for i in array:
			temp=max(i,temp+i)
			res=max(res,temp)
		return res

	def FindGreatestSumOfSubArray(self,array):
		maxList=[]
		tmp=0
		for a in array:
			tmp+=a
			if tmp>0:
				maxList.append(tmp)
			else:
				tmp=0
		if not maxList:
			return -1
		return max(maxList)