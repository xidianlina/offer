/*
题目描述:输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res;
		PermutationHelp(str, 0, res);
		return res;
	}
	void PermutationHelp(string str, int k, vector<string> &res)
	{
		if (k == str.size() - 1)
			res.push_back(str);
		unordered_set<char> us;//记录出现过的字符
		sort(str.begin() + k, str.end());//保证按字典序输出
		for (int i = k; i < str.size(); i++)
		{
			if (us.find(str[i]) == us.end())//只和没交换过的换
			{
				us.insert(str[i]);
				swap(str[i], str[k]);
				PermutationHelp(str,k+1,res);
				swap(str[i], str[k]); //复位
			}
		}
	}
};