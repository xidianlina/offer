# -*- coding:utf-8 -*-

#��Ŀ����:ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�HF��Ϊţ�͵�����Ԫ��,
#��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,
#�ñ��Ϊ0��С���ѿ�ʼ������ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,
#���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,
#���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��������������,�ĸ�С���ѻ�õ������Ʒ�أ�
#(ע��С���ѵı���Ǵ�0��n-1)

class Solution:
	def LastRemaining_Solution(self, n, m):
		if n<1 or m<1:
			return -1
		last=0
		for i in range(2,n+1):
			last=(last+m)%i
		return last

	def LastRemaining_Solution(self,n,m):
		if not m or not n:
			return -1
		res=range(n)
		i=0
		while len(res)>1:
			i=(m+i-1)%len(res)
			res.pop(i)
		return res[0]