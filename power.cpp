/*
题目描述:给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

class Solution {
public:
	double Power(double base, int exponent) {
		if (equal(base, 0.0)&exponent < 0)
			return 0.0;
		unsigned int absExponent = (unsigned int)(exponent);
		if (exponent < 0)
			absExponent = (unsigned int)(-exponent);
		double result = PowerWithExponent(base, absExponent);
		if (exponent < 0)
			result = 1.0 / result;
		return result;
	}
	double PowerWithExponent(double base, unsigned int exponent) {
		double result = 1.0;
		for (int i = 1; i <= exponent; i++)
			result *= base;
		return result;
	}
	bool equal(double num1, double num2) {
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
			return true;
		else
			return false;
	}
};