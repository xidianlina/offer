# -*- coding:utf-8 -*-

'''
题目描述:输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
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