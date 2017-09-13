/*
��Ŀ����:����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
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