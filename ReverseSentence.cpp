/*
��Ŀ����:ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*/

#include <string>

using namespace std;

class Solution {
public:
	//function first
	string ReverseSentence(string str) {
		string res = "", tmp = "";
		for (unsigned int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				res = " " + tmp + res;
				tmp = "";
			}
			else {
				tmp += str[i];
			}
		}
		if (tmp.size())
			res = tmp + res;
		return res;
	}

	//function second
	string ReverseSentence(string str)
	{
		if (str.empty())
			return str;
		reverse(str.begin(), str.end());
		size_t beg = 0;
		size_t end = 0;
		while (end != string::npos)
		{
			beg = str.find_first_not_of(' ', beg);
			end = str.find_first_of(' ', beg);
			if (beg == string::npos)
				return str;
			if (end == string::npos)
				reverse(str.begin() + beg, str.end());
			else {
				reverse(str.begin() + beg, str.begin() + end);
				beg = end + 1;
			}
		}
		return str;
	}
};