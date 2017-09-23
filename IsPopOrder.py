# -*- coding:utf-8 -*-

'''
题目描述:输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
'''

class Solution:
	def IsPopOrder(self, pushV, popV):
		pushLen=len(pushV)
		popLen=len(popV)
		stk=[]
		popIndex=0
		for i in range(0,pushLen):
			stk.append(pushV[i])
			while len(stk)!=0 and stk[-1]==popV[popIndex]:
				stk.pop()
				popIndex+=1
		return len(stk)==0

	def IsPopOrder(self,pushV,popV):
		if not pushV or len(pushV)!=len(popV):
			return False
		stk=[]
		for i in pushV:
			stk.append(i)
			while len(stk) and stk[-1]==popV[0]:
				stk.pop()
				popV.pop(0)
		if len(stk):
			return False
		return True