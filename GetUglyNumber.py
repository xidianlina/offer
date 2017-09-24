# -*- coding:utf-8 -*-

#题目描述:把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

class Solution:
	def GetUglyNumber_Solution(self, index):
		if index<=0:
			return 0
		if index==1:
			return 1
		uglyList=[1]
		t2,t3,t5=0,0,0
		for i in range(index-1):
			newUgly=min(uglyList[t2]*2,uglyList[t3]*3,uglyList[t5]*5)
			uglyList.append(newUgly)
			if newUgly%2==0:
				t2+=1
			if newUgly%3==0:
				t3+=1
			if newUgly%5==0:
				t5+=1
		return uglyList[-1]