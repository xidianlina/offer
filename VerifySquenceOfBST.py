# -*- coding:utf-8 -*-

#��Ŀ����:����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��

class Solution:
	def VerifySquenceOfBST(self, sequence):
		leng=len(sequence)
		if leng==0:
			return False
		if leng==1:
			return True
		root=sequence[-1]
		left=0
		while sequence[left]<root:
			left+=1
		for j in range(left,leng-1):
			if sequence[j]<root:
				return False
		return self.VerifySquenceOfBST(sequence[:left]) or self.VerifySquenceOfBST(sequence[left:leng-1])

	def VerifySquenceOfBST(self,sequence):
		if sequence is None:
			return False
		length=len(sequence)
		if length==0:
			return False
		if length==1:
			return True
		root=sequence[-1]
		i=0
		while sequence[i]<root:
			i=i+1
		k=i
		for j in range(i,length-1):
			if sequence[j]<root:
				return False
		left_s=sequence[:k]
		right_s=sequence[k:length-1]
		leftIs=True
		rightIs=True
		if len(left_s)>0:
			leftIs=self.VerifySquenceOfBST(left_s)
		if len(right_s)>0:
			rightIs=self.VerifySquenceOfBST(right_s)
		return leftIs and rightIs