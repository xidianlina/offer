/*
题目描述:写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

class Add {
public:
	//function first 递归
	int add(int num1, int num2)
	{
		if (num2 == 0)
			return num1;
		return add(num1^num2, (num1&num2) << 1);
	}

	//function second
	int add2(int num1, int num2)
	{
		while (num2 != 0)
		{
			int tmp = num1^num2;
			num2 = (num1&num2) << 1;
			num1 = tmp;
		}
		return num1;
	}
};