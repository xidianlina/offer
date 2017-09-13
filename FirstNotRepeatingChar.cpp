/*
��Ŀ����:��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
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