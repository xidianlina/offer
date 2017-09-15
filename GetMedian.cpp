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
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
public:
	void Insert(int num)
	{
		if (maxHeap.empty() || num <= maxHeap.top())
			maxHeap.push(num);
		else
			minHeap.push(num);
		if (maxHeap.size() == minHeap.size() + 2)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		if (maxHeap.size() + 1 == minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double GetMedian()
	{
		return maxHeap.size() == minHeap.size() ? (maxHeap.top() + minHeap.top()) / 2.0 : maxHeap.top();
	}
};