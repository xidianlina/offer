/*
题目描述:如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。
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