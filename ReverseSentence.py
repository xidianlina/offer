# -*- coding:utf-8 -*-

#��Ŀ����:ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
#ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I����
#��������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
#Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��

class Solution:
	def ReverseSentence(self, s):
		l=s.split(' ')
		return ' '.join(l[::-1])

	def ReverseSentence(self,s):
		if not s:
			return s
		s=s.split(" ")
		news=[]
		for word in range(len(s)-1,-1,-1):
			news.append(s[word])
			if word:
				news.append(" ")
		return "".join(news)