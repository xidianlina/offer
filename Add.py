# -*- coding:utf-8 -*-

#��Ŀ����:дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�

class Solution:
	def Add(self, num1, num2):
		while num2:
			temp=num1^num2
			num2=(num1&num2)<<1
			num1=temp
		return num1

	def Add(self,num1,num2):
		return sum([num1,num2])