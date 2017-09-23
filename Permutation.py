# -*- coding:utf-8 -*-

#题目描述:输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

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