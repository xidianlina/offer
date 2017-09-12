/*
��Ŀ����:��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
		//����һ������Partition������O(n)�㷨
		int MoreThanHalfNum_Solution(vector<int> numbers) {
		int length = numbers.size();
		if (numbers.empty() || length<0)
			return 0;
		int middle = length >> 1;
		int start = 0;
		int end = length - 1; 
		int index = partition(numbers, start, end);
		while (index != middle)
		{
			if (index>middle)
			{
				end = index - 1;
				index = partition(numbers, start, end);
			}
			else
			{
				start = index + 1;
				index = partition(numbers, start, end);
			}
		}
		int result = numbers[middle];           
		if (!CheckMoreThanHAlf(numbers, length, result))    
			return 0;
		return result;
	}

	int partition(vector<int> input, int low, int high)
	{
		int pivotkey = input[low];   
		while (low<high)
		{
			while (low<high&&pivotkey<input[high])
				high--;
			swap(&input[low], &input[high]);
			while (low<high&&pivotkey >= input[low])
				low++;
			swap(&input[low], &input[high]);
		}
		return low;
	}

	/*���partition���Ż��˲���Ҫ�Ľ�������swap�ø�ֵ�滻
	int partition(vector<int> &input, int begin, int end)
	{
		int low = begin;
		int high = end;
		int pivot = input[low];
		while (low < high)
		{
		while (low < high&&pivot <= input[high])
		high--;
		input[low] = input[high];         //�Ż�����Ҫ���滻
		while (low < high&&pivot >= input[low])
		low++;
		input[high] = input[low];         //�Ż�����Ҫ���滻
		}
		input[low] = pivot;
		return low;
	}
	*/

	bool CheckMoreThanHAlf(vector<int> numbers, int length, int result)    //���result��ֵ�ĸ����Ƿ�������������һ��
	{
		int times = 0;
		for (int i = 0; i<length; ++i)
		{
			if (numbers[i] == result)
				times++;
		}
		if (times * 2 <= length)
			return false;
		return true;
	}

	void swap(int *a, int *b)   //����������
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	//��������Ħ��ͶƱ��
		int MoreThanHalfNum(vector<int> numbers) {
			int num = numbers[0], cnt = 1;
			for (int i = 1; i < numbers.size(); i++)
			{
				if (numbers[i] == num)
					cnt++;
				else {
					if (--cnt == 0)
					{
						num = numbers[i];
						cnt = 1;
					}
				}
			}

		cnt = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == num)
				cnt++;
		}
		if (2 * cnt > numbers.size()) 
			return num;
		else 
			return 0;
	}
};