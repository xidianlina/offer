/*
��Ŀ����:��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*/

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str[0] == '\0'&&pattern[0] == '\0')
			return true;
		else if (str[0] != '\0'&&pattern[0] == '\0')
			return false;
		if (pattern[1] != '*') {
			if (str[0] == pattern[0] || (pattern[0] == '.'&&str[0] != '\0'))
				return match(str + 1, pattern + 1);
			else
				return false;
		}
		else {
			if (str[0] == pattern[0] || (pattern[0] == '.'&&str[0] != '\0'))
				/*
				���ֿ��ܣ�
				1��ģʽ����ǰ�ַ�����0�Σ���*��ʾ��ǰ�ַ�����0�Σ���str=str,pattern=pattern+2;
				2��ģʽ����ǰ�ַ�����1�Σ���*��ʾ��ǰ�ַ�����1�Σ���str=str+1,pattern=pattern+2;
				3��ģʽ����ǰ�ַ�����2�λ�2�����ϣ���*��ʾ��ǰ�ַ�����2�λ����ϣ���str=str+1,pattern=pattern;
				*/
				return match(str, pattern + 2) || match(str + 1, pattern) || match(str + 1, pattern + 2);
			else
				/*
				�ų�������a��a*a
				���ں��滹��һ��a����ǰ��a*��Ҫ���� "0",����str[]��pattern[]���,Ҳ����ȥ����������ͬ
				����match(str,pattern+2)���Ҳ��Ҫ����				
				*/
				return match(str, pattern + 2);
		}
	}
};