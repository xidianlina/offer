# -*- coding:utf-8 -*-

#��Ŀ����:����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��

import itertools
class Solution:
	def Permutation(self, ss):
		if not ss:
			return []
		return sorted(list(set(map(''.join,itertools.permutations(ss)))))

	def Permutation(self,ss):
		if not ss:
			return []
		
		self.vis=[0 for i in range(len(ss))]
		self.ans=[]
		self.temp=""
		self.DFS(0,ss)
		return sorted([i for i in set(self.ans)])

	def DFS(self,sum,ss):
		if sum==len(ss):
			self.ans.append(self.temp)
			return
		for idx in range(len(ss)):
			if self.vis[idx]==0:
				self.vis[idx]=1
				self.temp+=ss[idx]
				self.DFS(sum+1,ss)
				self.temp=self.temp[:-1]
				self.vis[idx]=0