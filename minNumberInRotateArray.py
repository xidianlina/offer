# -*- coding:utf-8 -*-

'''
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
'''

class Solution:
	def minNumberInRotateArray(self,rotateArray):
		length=len(rotateArray)
		if length==0:
			return 0
		if length==1:
			return rotateArray[0]
		left,right=0,length-1

		while left<=right:
			mid=(left+right)>>1
			if rotateArray[mid]>rotateArray[right]:
				left=mid+1
			elif rotateArray[mid]<rotateArray[right]:
				right=mid
			else:
				right-=1
			if left>=right:
				break
		return rotateArray[left]

	def minNumberInRotateArray2(self,rotateArray):
		if rotateArray:
			length=len(rotateArray)
			if length==1:
				return rotateArray[0]
			for i in range(length-1):
				if rotateArray[i]>rotateArray[i+1]:
					return rotateArray[i+1]
			return rotateArray[0]
		return 0
	
	def minNumberInRotateArray(self,rotateArray):
		if rotateArray==None or len(rotateArray)==0:
			return 0
		if rotateArray[0]<rotateArray[-1]:
			return rotateArray[0]
		left,right=0,len(rotateArray)-1
		while left<=right:
			if right-left==1:
				mid=right
				break
			mid=(left+right)>>1

			if rotateArray[mid]==rotateArray[left]==rotateArray[right]:
				return self.ordersearch(rotateArray,left,right)
			
			if rotateArray[left]<=rotateArray[mid]:
				left=mid
			elif rotateArray[mid]>=rotateArray[right]:
				right=mid
		return rotateArray[mid]

	def ordersearch(self,rotateArray,left,right):
		res=rotateArray[left]
		for i in range(left+1,right+1):
			res=min(res,rotateArray[i])
		return res