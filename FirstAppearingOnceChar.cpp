/*
��Ŀ����:��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
*/

#include <string>

using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	string s;
	char hash[256] = { 0 };
	void Insert(char ch)
	{
		s += ch;
		hash[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int size = s.size();
		for (int i = 0; i < size; i++)
			if (hash[s[i]] == 1)
				return s[i];
		return '#';
	}
};