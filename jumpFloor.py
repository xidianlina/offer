# -*- coding:utf-8 -*-

'''
��Ŀ����:һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
'''

class Solution:
    def jumpFloor(self, number):
        # write code here
		a=1
		b=1
		for i in range(number):
			a,b=b,a+b
		return a

	def jumpFloor(self,number):
		if number<=0:
			return 1
		elif number<=2:
			return number
		else:
			a,b=1,2
			for i in range(2,number):
				a,b=b,a+b
			return b