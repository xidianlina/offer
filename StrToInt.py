# -*- coding:utf-8 -*-

#题目描述:将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

class Solution:
	def StrToInt(self, s):
		try:
			return int(s)
		except Exception as e:
			return 0

	def StrToInt(self,s):
		if len(s)==0:
			return 0
		else:
			if s[0]>'9' or s[0]<'0':
				res=0
			else:
				res=int(s[0])*10**(len(s)-1)
			if len(s)>1:
				for i in range(1,len(s)):
					if s[i]>='0' and s[i]<='9':
						res=res+int(s[i])*10**(len(s)-1-i)
					else:
						return 0
			if s[0]=='+':
				return res
			if s[0]=='-':
				return -res
			return res

		    def StrToInt(self, s):
        if not s:
            return 0
        str2num={'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'0':0}
        flag2num={'-':-1,'+':1}
        first=s[0]
        if first in ['+','-']:
            flag=flag2num[first]
            x=0
            for i in s[1:]:
                if i not in str2num:
                    return 0
                x=x*10+str2num[i]
            return flag*x
        else:
            x=0
            for i in s:
                if i not in str2num:
                    return 0
                x=x*10+str2num[i]
            return x