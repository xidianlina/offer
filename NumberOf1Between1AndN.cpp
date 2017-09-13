/*
题目描述:输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。
*/

class Solution {
public:
	//function first 时间复杂度O(n*logn)
	int NumberOf1Between1AndN(int n)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp = i;
			while (tmp)
			{
				if (tmp % 10 == 1)
					res++;
				tmp /= 10;
			}
		}
		return res;
	}

	//function second 时间复杂度O(logn)
	int NumberOf1Between1AndN2(int n)
	{
		int ones = 0;
		for (long long m = 1; m <= n; m *= 10) {
			int a = n / m, b = n%m;
			if (a % 10 == 0)
				ones += a / 10 * m;
			else if (a % 10 == 1)
				ones += (a / 10 * m) + (b + 1);
			else
				ones += (a / 10 + 1)* m;
		}
		return ones;
	}
};