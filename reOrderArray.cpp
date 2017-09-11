/*
题目描述:输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() == 0)
			return;
		int i = 0;
		int j = 0;
		while (i < array.size()) {
			while (i < array.size() && !isEven(array[i]))
				i++;
			j = i + 1;
			while (j < array.size() && isEven(array[j]))
				j++;
			if (j < array.size()) {
				int tmp = array[j];
				for (int k = j - 1; k >= i; k--)
					array[k + 1] = array[k];
				array[i++] = tmp;
			}
			else
				break;
		}
	}

	bool isEven(int num) {
		if (num % 2 == 0)
			return true;
		return false;
	}
};