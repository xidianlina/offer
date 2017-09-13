/*
��Ŀ����:��ֻ��������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ����������7�� ϰ�������ǰ�1�����ǵ�һ��������
�󰴴�С�����˳��ĵ�N��������
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