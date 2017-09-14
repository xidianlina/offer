/*
题目描述:对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
*/

#include <string>

using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		int size = str.length();
		if (size == 0 || str.empty())
			return "";
		n = n%size;
		str = str + str;
		return str.substr(n, size);
	}
};