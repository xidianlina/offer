# -*- coding:utf-8 -*-

'''
题目描述:一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
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