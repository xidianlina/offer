# -*- coding:utf-8 -*-

#题目描述:在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置

class Solution:
	def FirstNotRepeatingChar(self, s):
		if not s:
			return -1
		for i,ch in enumerate(s):
			if s.count(ch)==1:
				return i

	def FirstNotRepeatingChar(self,s):
		index=0
		if len(s)==0:
			return -1
		else:
			for x in s:
				if s.count(x)==1:
					return index
				index+=1