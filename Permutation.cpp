/*
��Ŀ����:����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
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
		unordered_set<char> us;//��¼���ֹ����ַ�
		sort(str.begin() + k, str.end());//��֤���ֵ������
		for (int i = k; i < str.size(); i++)
		{
			if (us.find(str[i]) == us.end())//ֻ��û�������Ļ�
			{
				us.insert(str[i]);
				swap(str[i], str[k]);
				PermutationHelp(str,k+1,res);
				swap(str[i], str[k]); //��λ
			}
		}
	}
};