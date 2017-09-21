# -*- coding:utf-8 -*-

'''
题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
'''

class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        res = ''
        for str in s:
            if str.strip():
                res+=str
            else:
                res+='%20'
        return res
		
	def replaceSpace2(self,s):
		s_r = ''
        for i in range(len(s)):
            if s[i] !=  ' ':
                s_r += s[i]
            else:
                s_r += '%20'
        return s_r
		
	def replaceSpace3(self,s):
		return "".join(str if str is not " " else '%20' for str in s)