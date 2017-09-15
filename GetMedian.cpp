/*
��Ŀ����:��εõ�һ���������е���λ����������������ж�����������ֵ��
��ô��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ��
��ô��λ������������ֵ����֮���м���������ƽ��ֵ��
*/

#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
	priority_queue<int, vector<int>, less<int>> min;
	priority_queue<int, vector<int>, greater<int>> max;
public:
	void Insert(int num)
	{
		if (min.empty() || num <= min.top())
			min.push(num);
		else
			max.push(num);
		if (min.size() == max.size() + 2)
		{
			max.push(min.top());
			min.pop();
		}
		if (min.size() + 1 == max.size())
		{
			min.push(max.top());
			max.pop();
		}
	}

	double GetMedian()
	{
		return min.size() == max.size() ? (min.top() + max.top()) / 2.0 : min.top();
	}
};