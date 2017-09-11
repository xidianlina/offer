/*
��Ŀ����:����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
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