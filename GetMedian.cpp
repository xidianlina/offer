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