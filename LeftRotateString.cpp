/*
��Ŀ����:����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
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