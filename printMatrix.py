# -*- coding:utf-8 -*-

'''
题目描述:输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
'''

class Solution:
	def printMatrix(self, matrix):
		row=len(matrix)
		col=len(matrix[0])
		res=[]
		if row==0 or col==0:
			return res

		l,t,r,b=0,0,col-1,row-1
		while l<=r and t<=b:
			for i in range(l,r+1):
				res.append(matrix[t][i])
			for i in range(t+1,b+1):
				res.append(matrix[i][r])
			if t!=b:
				for i in range(r-1,l-1,-1):
					res.append(matrix[b][i])
			if l!=r:
				for i in range(b-1,t,-1):
					res.append(matrix[i][l])
			l+=1
			t+=1
			r-=1
			b-=1
		return res