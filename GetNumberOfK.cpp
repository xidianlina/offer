/*
题目描述:统计一个数字在排序数组中出现的次数。
*/

#include <vector>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty() || data.size() == 0)
			return 0;
		int left = 0;
		int right = data.size() - 1;
		int mid = 0;
		int res = 0;
		while (left < right)
		{
			mid = (left + right) >> 1;
			if (data[mid] == k)
			{
				res = mid;
				break;
			}
			else if (data[mid] > k)
				right = mid - 1;
			else
				left = mid + 1;
		}
		int total = 0;
		for (int i = res+1; i < data.size(); i++)
			if (data[i] == k)
				total++;
		for (int i = res; i >= 0; i--)
			if (data[i] == k)
				total++;
		return total;
	}
};