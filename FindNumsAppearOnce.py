# -*- coding:utf-8 -*-

#题目描述:一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

class Solution:
	def FindNumsAppearOnce(self, array):
		tmp=set()
		for a in array:
			if a in tmp:
				tmp.remove(a)
			else:
				tmp.add(a)
		return list(tmp)

	def FindNumsAppearOnce(self,array):
		if len(array)<2:
			return array
		xor=reduce(lambda x,y:x^y,array)
		if xor!=1:
			xor=xor&(~xor+1)
		lst1=[]
		lst2=[]
		for i in array:
			if i&xor:
				lst1.append(i)
			else:
				lst2.append(i)
		return [reduce(lambda x,y:x^y,lst1),reduce(lambda x,y:x^y,lst2)]

	def FindNumsAppearOnce(self,array):
		length=len(array)
		sum=0
		if array is None or length<2:
			return []
		for i in range(length):
			sum^=array[i]
		n=1
		while sum&n==0:
			n=n<<1
		x1=0
		x2=0
		for i in range(length):
			if array[i]&n:
				x1^=array[i]
			else:
				x2^=array[i]
		return [x1,x2]