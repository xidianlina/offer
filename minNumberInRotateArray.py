# -*- coding:utf-8 -*-

'''
��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
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