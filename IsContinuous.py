# -*- coding:utf-8 -*-

#��Ŀ����:LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
#��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
#������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,
#����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����
#LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�
#Ϊ�˷������,�������Ϊ��С����0��

class Solution:
	def IsContinuous(self, numbers):
		length=len(numbers)
		if length!=5:
			return False
		numbers.sort()
		jokers=0
		for i in range(0,5):
			if numbers[i]==0:
				jokers+=1
		for i in range(jokers+1,5):
			if numbers[i]==numbers[i-1]:
				return False
		dis=numbers[4]-numbers[jokers]
		if dis<=4:
			return True
		return False