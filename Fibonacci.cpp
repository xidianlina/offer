/*
题目描述:大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
*/

#include <iostream>

class Solution {
public:
	int Fibonacci1(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return Fibonacci1(n - 1) + Fibonacci1(n - 2);
	}
	int Fibonacci2(int n) {
		int res[] = { 0,1 };
		if (n < 2)
			return res[n];
		int fibOne = 1;
		int fibTwo = 0;
		int fibN = 0;
		for (int i = 2; i <= n; i++) {
			fibN = fibOne + fibTwo;
			fibTwo = fibOne;
			fibOne = fibN;
		}
		return fibN;
	}
};