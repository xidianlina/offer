# -*- coding:utf-8 -*-

#��Ŀ����:��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7�� ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

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