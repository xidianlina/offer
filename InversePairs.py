# -*- coding:utf-8 -*-

#��Ŀ����:�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007

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