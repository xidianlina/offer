/*
输入一个正整数S，找出所有和为S的连续的正数序列（至少包含2个数）。
*/

#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		if (sum < 1)
			return res;
		int start = 1;
		int end = 2;
		while (start != (1 + sum) / 2)
		{
			int curSum = (start + end)*(end - start + 1) / 2;
			if (curSum == sum)
			{
				vector<int> tmp;
				for (int i = start; i <= end; i++)
					tmp.push_back(i);
				res.push_back(tmp);
				tmp.clear();
				start++;
				end++;
			}
			else if (curSum < sum)
				end++;
			else start++;
		}
		return res;
	}
};