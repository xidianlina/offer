/*
题目描述:输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
*/

#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
	//方法一
	vector<int> GetLeastNumbers(vector<int> input, int k)
	{
		vector<int> result;
		int len = input.size();
		if (input.empty() || k <= 0 || len < k)
			return result;

		multiset<int, greater<int> > leastNumbers; // 从大到小排序
		multiset<int, greater<int> >::iterator iterGreater; // 定义迭代器

		vector<int>::iterator iter = input.begin();
		for (; iter != input.end(); ++iter)
		{
			// 将前k个数直接插入进multiset中，注意是小于K
			if (leastNumbers.size() < k)
			{
				leastNumbers.insert(*iter);
			}
			else
			{
				// 因为设置的从大到小排序，故multiset中第一个位置的元素即为最大值
				iterGreater = leastNumbers.begin();

				// 如果input中当前元素比multiset中最大元素小，则替换；即保持multiset中这k个元素是最小的。
				if (*iter < *(leastNumbers.begin()))
				{
					// 替换掉当前最大值
					leastNumbers.erase(iterGreater);
					leastNumbers.insert(*iter);
				}
			}
		}

		for (iterGreater = leastNumbers.begin(); iterGreater != leastNumbers.end(); ++iterGreater)
		{
			result.push_back(*iterGreater); // 将multiset中这k个元素输出
		}

		return result;
	}

	//方法二
	int Partition(vector<int>& input, int begin, int end)
	{
		int low = begin;
		int high = end;

		int pivot = input[low];
		while (low<high)
		{
			while (low<high&&pivot <= input[high])
				high--;
			input[low] = input[high];
			while (low<high&&pivot >= input[low])
				low++;
			input[high] = input[low];
		}
		input[low] = pivot;
		return low;
	}

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len == 0 || k>len)
			return vector<int>();
		if (len == k) 
			return input;

		int start = 0;
		int end = len - 1;
		int index = Partition(input, start, end);
		while (index != (k - 1))
		{
			if (index>k - 1)
			{
				end = index - 1;
				index = Partition(input, start, end);
			}
			else
			{
				start = index + 1;
				index = Partition(input, start, end);
			}
		}
		vector<int> res(input.begin(), input.begin() + k);

		return res;
	}
	//方法三
		vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len) return 
			vector<int>();

		vector<int> res(input.begin(), input.begin() + k);
		//建堆
		make_heap(res.begin(), res.end());

		for (int i = k; i<len; i++)
		{
			if (input[i]<res[0])
			{
				//先pop,然后在容器中删除
				pop_heap(res.begin(), res.end());
				res.pop_back();
				//先在容器中加入，再push
				res.push_back(input[i]);
				push_heap(res.begin(), res.end());
			}
		}
		//使其从小到大输出
		sort_heap(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> vec = { 4,5,1,6,2,7,3,8 };
	vector<int> res=s.GetLeastNumbers_Solution(vec, 4);
	for (unsigned int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}