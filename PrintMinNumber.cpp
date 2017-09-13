/*
题目描述:输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		string result;
		if (numbers.size() == 0)
		return result;
		vector<string> strNum;
		for (int i = 0; i < numbers.size(); i++)
		{
			stringstream ss;
			ss << numbers[i];
			string s = ss.str();
			strNum.push_back(s);
		}
		sort(strNum.begin(), strNum.end(), compare);
		for (int i = 0; i < strNum.size(); i++)
			result.append(strNum[i]);
		return result;
	}
	static bool compare(string str1, string str2)
	{
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		return s1 < s2;
	}
};