/*
题目描述:将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0
*/

#include <string>

using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int sum = 0;
		int sign = 1;
		int i = 0;
		int size = str.size();
		while (i < size&&str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-') {
			sign = (str[i++] == '+') ? 1 : -1;
		}
		if (str[i] >= '1'&&str[i] <= '9')
			sum = str[i++] - '0';
		for (int j = i; j < size; j++)
		{
			if (str[j]<'1' || str[j]>'9')
				return 0;
			sum = sum * 10 + str[j] - '0';
		}
		return sum*sign;
	}
};