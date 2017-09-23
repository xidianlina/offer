# -*- coding:utf-8 -*-

'''
��Ŀ����:���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
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