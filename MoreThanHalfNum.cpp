/*
题目描述:数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
		//方法一：基于Partition函数的O(n)算法
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

	/*这个partition是优化了不必要的交换，将swap用赋值替换
	int partition(vector<int> &input, int begin, int end)
	{
		int low = begin;
		int high = end;
		int pivot = input[low];
		while (low < high)
		{
		while (low < high&&pivot <= input[high])
		high--;
		input[low] = input[high];         //优化不必要的替换
		while (low < high&&pivot >= input[low])
		low++;
		input[high] = input[low];         //优化不必要的替换
		}
		input[low] = pivot;
		return low;
	}
	*/

	bool CheckMoreThanHAlf(vector<int> numbers, int length, int result)    //检查result的值的个数是否大于整个数组的一半
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

	void swap(int *a, int *b)   //交换两个数
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	//方法二：摩尔投票法
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