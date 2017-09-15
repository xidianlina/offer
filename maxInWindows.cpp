/*
��Ŀ����:����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6����
{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}��
{2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*/

#include <vector>

using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		int len = num.size();
		if (num.empty() || size <= 0 || len == 0)
			return res;
		int max;
		for (int i = 0; i < len - size + 1; i++)
		{
			max = num[i];
			for (int j = i; j < i + size; j++)
			{
				if (num[j] > max)
					max = num[j];
			}
			res.push_back(max);
		}
		return res;
	}
};