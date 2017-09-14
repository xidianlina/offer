/*
0，1，...，n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。
求出这个圆圈剩下的最后一个数字。
*/

#include <list>

using namespace std;

class Solution {
public:
	//function first
	int LastRemaining(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;
		unsigned int i = 0;
		list<int> numbers;
		for (i = 0; i < n; i++)
			numbers.push_back(i);
		list<int>::iterator current = numbers.begin();
		while (numbers.size() > 1)
		{
			for (int i = 1; i < m; i++)
			{
				current++;
				if (current == numbers.end())
					current = numbers.begin();
			}
			list<int>::iterator next = ++current;
			if (next == numbers.end())
				next = numbers.begin();
			--current;
			numbers.erase(current);
			current = next;
		}
		return *(current);
	}

	//function second
	int LastRemaining2(int n, int m) {
		if (n < 1 || m < 1)
			return -1;
		int last = 0;
		for (int i = 2; i <= n; i++)
			last = (last + m) % i;
		return last;
	}
};