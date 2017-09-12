/*
��Ŀ����:����n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4��
*/

#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
	//����һ
	vector<int> GetLeastNumbers(vector<int> input, int k)
	{
		vector<int> result;
		int len = input.size();
		if (input.empty() || k <= 0 || len < k)
			return result;

		multiset<int, greater<int> > leastNumbers; // �Ӵ�С����
		multiset<int, greater<int> >::iterator iterGreater; // ���������

		vector<int>::iterator iter = input.begin();
		for (; iter != input.end(); ++iter)
		{
			// ��ǰk����ֱ�Ӳ����multiset�У�ע����С��K
			if (leastNumbers.size() < k)
			{
				leastNumbers.insert(*iter);
			}
			else
			{
				// ��Ϊ���õĴӴ�С���򣬹�multiset�е�һ��λ�õ�Ԫ�ؼ�Ϊ���ֵ
				iterGreater = leastNumbers.begin();

				// ���input�е�ǰԪ�ر�multiset�����Ԫ��С�����滻��������multiset����k��Ԫ������С�ġ�
				if (*iter < *(leastNumbers.begin()))
				{
					// �滻����ǰ���ֵ
					leastNumbers.erase(iterGreater);
					leastNumbers.insert(*iter);
				}
			}
		}

		for (iterGreater = leastNumbers.begin(); iterGreater != leastNumbers.end(); ++iterGreater)
		{
			result.push_back(*iterGreater); // ��multiset����k��Ԫ�����
		}

		return result;
	}

	//������
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
	//������
		vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int len = input.size();
		if (len <= 0 || k>len) return 
			vector<int>();

		vector<int> res(input.begin(), input.begin() + k);
		//����
		make_heap(res.begin(), res.end());

		for (int i = k; i<len; i++)
		{
			if (input[i]<res[0])
			{
				//��pop,Ȼ����������ɾ��
				pop_heap(res.begin(), res.end());
				res.pop_back();
				//���������м��룬��push
				res.push_back(input[i]);
				push_heap(res.begin(), res.end());
			}
		}
		//ʹ���С�������
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