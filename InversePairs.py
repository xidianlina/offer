# -*- coding:utf-8 -*-

#题目描述:在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

class Solution:
	def InversePairs(self, data):
		length=len(data)
		if length<=0:
			return 0
		copy=[]
		for i in range(length):
			copy.append(data[i])
		cnt=self.inversePairsCore(data,copy,0,length-1)
		return cnt%1000000007

	def inversePairsCore(self,data,copy,start,end):
		if start==end:
			copy[start]==data[start]
			return 0
		length=(end-start)/2
		left=self.inversePairsCore(copy,data,start,start+length)
		right=self.inversePairsCore(copy,data,start+length+1,end)
		i=start+length
		j=end
		indexcopy=end
		cnt=0
		while i>=start and j>=start+length+1:
			if data[i]>data[j]:
				copy[indexcopy]=data[i]
				indexcopy-=1
				i-=1
				cnt=cnt+j-start-length
			else:
				copy[indexcopy]=data[j]
				indexcopy-=1
				j-=1
		while i>=start:			
			copy[indexcopy]=data[i]
			indexcopy-=1
			i-=1
		while j>=start+length+1:
			copy[indexcopy]=data[j]
			indexcopy-=1
			j-=1
		return left+right+cnt