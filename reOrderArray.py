# -*- coding:utf-8 -*-

'''
��Ŀ����:����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
'''

class Solution:
    def reOrderArray(self,array):
        x=len(array)
        for i in range(0,x):
            for j in range(x-1,i,-1):
                if array[j-1]%2==0 and array[j]%2==1:
                    array[j-1],array[j]=array[j],array[j-1]
        return array

    def reOrderArray(self, array):
        odd=deque()
        x=len(array)
        for i in range(x):
            if array[x-i-1]%2!=0:
                odd.appendleft(array[x-i-1])
            if array[i]%2==0:
                odd.append(array[i])
        return list(odd)

	def reOrderArray(self,array):
		l=[]
		r=[]
		for i in range(len(array)):
			if array[i]%2:
				l.append(array[i])
			else:
				r.append(array[i])

		return l+r

	def reOrderArray(self,array):
		is_even=lambda x:x%2==0
		even=[i for i in array if is_even(i)]
		odd=[i for i in array if not is_even(i)]
		odd.extend(even)
		return odd