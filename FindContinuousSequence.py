# -*- coding:utf-8 -*-

#��Ŀ����������һ��������S���ҳ����к�ΪS���������������У����ٰ���2��������


class Solution:
	def FindContinuousSequence(self, sum):
		res=[]
		if sum<1:
			return res
		start=1
		end=2
		while start!=(1+sum)/2:
			curSum=(start+end)*(end-start+1)/2
			if curSum==sum:
				tmp=[]
				for i in range(start,end+1):
					tmp.append(i)
				res.append(tmp)
				start+=1
				end+=1
			elif curSum<sum:
				end+=1
			else:
				start+=1
		return res

			