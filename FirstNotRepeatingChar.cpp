/*
题目描述:在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.empty() || str.size() == 0)
			return -1;
		vector<int> vec(256, 0);
		for (char c : str)
			vec[int(c)]++;
		for (int i = 0; i < str.size(); i++)
			if (vec[int(str[i])] == 1)
				return i;
		return -1;
	}
};