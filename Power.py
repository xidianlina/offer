# -*- coding:utf-8 -*-

'''
��Ŀ����:����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
'''

class Solution:
	def Power(self, base, exponent):
		# write code here
		if base==0:
			return 0.0
		if base==1 or exponent==0:
			return 1
		if exponent==1:
			return base
		result=1
		for i in range(abs(exponent)):
			result*=base
		if exponent<0:
			result=1/result
		return result