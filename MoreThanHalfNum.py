# -*- coding:utf-8 -*-

#��Ŀ����:��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

class Solution:
	def MoreThanHalfNum_Solution(self, numbers):
		num=numbers[0]
		cnt=1
		for i in range(1,len(numbers)):
			if numbers[i]==num:
				cnt+=1
			else:
				cnt-=1
				if cnt==0:
					num=numbers[i]
					cnt=1
		cnt=0
		for i in range(0,len(numbers)):
			if numbers[i]==num:
				cnt+=1
		if 2*cnt>len(numbers):
			return num
		return 0

	def MoreThanHalfNum_Solution(self,numbers):
		import collections
		temp=collections.Counter(numbers)
		x=len(numbers)/2
		for k,v in temp.items():
			if v>x:
				return k
		return 0

	def MoreThanHalfNum_Solution(self,numbers):
		numbers.sort()
		theone=numbers[len(numbers)/2]
		if numbers.count(theone)>len(numbers)/2:
			return theone
		return 0

	def MoreThanHalfNum_Solution(self,numbers):
		if not numbers:
			return 0
		res=numbers[0]
		times=1
		length=len(numbers)
		for i in range(length):
			if times==0:
				res=numbers[i]
			elif res==numbers[i]:
				times+=1
			else:
				times-=1
		import collections
		return res if collections.Counter(numbers)[res]*2>length else 0