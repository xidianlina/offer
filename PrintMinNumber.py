# -*- coding:utf-8 -*-

#��Ŀ����:����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

class Solution:
	def PrintMinNumber(self, numbers):
		if not numbers:
			return ""
		lmb=lambda n1,n2:int(str(n1)+str(n2))-int(str(n2)+str(n1))
		array=sorted(numbers,cmp=lmb)
		return ''.join([str(i) for i in array])

	def PrintMinNumber(self,numbers):
		if not numbers:
			return ""
		num=map(str,numbers)
		num.sort(lambda x,y:cmp(x+y,y+x))
		return ''.join(num)