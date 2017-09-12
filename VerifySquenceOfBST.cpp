/*
��Ŀ����:����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		if (sequence.size() == 0)
			return false;
		if (sequence.size() == 1)
			return true;
		return judge(sequence, 0, sequence.size() - 1);
	}
	bool judge(vector<int> sequence, int start, int end)
	{
		if (start >= end)
			return true;
		int i = end;
		while (i > start&&sequence[i - 1] > sequence[end])
			i--;
		for (int j = start; j < i - 1; j++)
			if (sequence[j] > sequence[end])
				return false;
		return judge(sequence, start, i - 1) && judge(sequence, i, end - 1);
	}
};