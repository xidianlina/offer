# -*- coding:utf-8 -*-

'''
��Ŀ����:һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
'''

class Solution:
    def jumpFloorII(self, number):
        # write code here
		if number==1:
			return 1
		if number==2:
			return 2
		if number>=3:
			s=[]
			s.append(1)
			s.append(2)
			for i in range(2,number):
				s.append(sum(s)+1)
		return s[-1]