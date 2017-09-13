/*
��Ŀ����:һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/

#include <vector>

using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int len = data.size();
		int sum = 0;
		if (data.empty() || len < 2)
			return;
		for (int i = 0; i<len; ++i)
			sum ^= data[i];
		int n = 1;
		while ((sum & n) == 0)//�ҳ����ұߵ�1����Ϊ0��λ��
			n = n << 1;
		int x1 = 0, x2 = 0;
		for (int i = 0; i<len; ++i)
			if (data[i] & n)//���ݵ�һ����Ϊ0��λ�����½�������л���
				x1 ^= data[i];
			else
				x2 ^= data[i];
		*num1 = x1;
		*num2 = x2;
	}
};