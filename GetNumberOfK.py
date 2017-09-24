# -*- coding:utf-8 -*-

#题目描述:统计一个数字在排序数组中出现的次数。

class Solution:
	def GetNumberOfK(self, data, k):
		return data.count(k)

	def GetNumberOfK(self,data,k):
		if not data:
			return 0
		low=0
		high=len(data)-1
		cnt=0
		end=len(data)-1
		while low<=high:
			mid=(low+high)/2
			if data[mid]==k:
				while mid>=0 and data[mid]==k:
					mid-=1
				mid+=1
				while mid<=end and data[mid]==k:
					mid+=1
					cnt+=1
				return cnt
			elif data[mid]<k:
				low=mid+1
			else:
				high=mid-1
		return cnt