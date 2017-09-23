# -*- coding:utf-8 -*-

#��Ŀ����:����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��

class Solution:
	def GetLeastNumbers_Solution(self, tinput, k):
		if tinput is None:
			return
		n=len(tinput)
		if n<k:
			return []
		tinput=sorted(tinput)
		return tinput[:k]

	def GetLeastNumbers_Solution(self, tinput, k):
		if not tinput or not k or k > len(tinput):
			return []
		import heapq
		heapq.heapify(tinput)
		return [heapq.heappop(tinput) for _ in range(k)]

    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        length=len(tinput)
        if length<k:
            return []
        start,end=0,length-1
        tinput=self.partition(tinput,start,end)
        return tinput[:k]
         
    def partition(self,tinput,start,end):
        if start>=end:
            return tinput
        temp=tinput[start]
        i,j=start,end
        while i<j:
            while i<j and temp<=tinput[j]:
                j-=1
            if i<j:
                tinput[i]=tinput[j]
                i+=1
            while i<j and temp>tinput[i]:
                i+=1
            if i<j:
                tinput[j]=tinput[i]
                j-=1
        tinput[i]=temp
        self.partition(tinput,start,i-1)
        self.partition(tinput,i+1,end)
        return tinput