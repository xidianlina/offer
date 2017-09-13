/*
题目描述:把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
*/

#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//functino first
	int GetUglyNumber(int index) {
		if (index == 0)
			return 0;
		int n = 1, ugly = 1;
		list<int> q2;
		list<int> q3;
		list<int> q5;
		q2.push_back(2);
		q3.push_back(3);
		q5.push_back(5);
		while (n != index)
		{
			ugly = min(min(q2.front(), q3.front()), q5.front());
			if (ugly == q2.front())
			{
				q2.push_back(ugly * 2);
				q3.push_back(ugly * 3);
				q5.push_back(ugly * 5);
				q2.pop_front();
			}
			if (ugly == q3.front())
			{
				q3.push_back(ugly * 3);
				q5.push_back(ugly * 5);
				q3.pop_front();
			}
			if (ugly == q5.front())
			{
				q5.push_back(ugly * 5);
				q5.pop_front();
			}
			n++;
		}
		return ugly;
	}

	//function second
	int GetUglyNumber_Solution(int index) {
		if (index <= 0) 
			return 0;
		if (index == 1) 
			return 1;
		vector<int> k(index); 
		k[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i<index; i++) {
			k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
			if (k[i] == k[t2] * 2)
				t2++;
			if (k[i] == k[t3] * 3)
				t3++;
			if (k[i] == k[t5] * 5)
				t5++;
		}
		return k[index - 1];
	}
};