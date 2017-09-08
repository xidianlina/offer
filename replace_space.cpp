///*
//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
//*/
//
//#include <iostream>
//
//class Solution {
//public:
//	void replaceSpace(char *str, int length) {
//		if (str == NULL || length < 0)
//			return;
//		int i = 0;
//		int oldnumber = 0;
//		int replacenumber = 0;
//		while (str[i] != '\0')
//		{
//			oldnumber++;
//			if (str[i] == ' ')
//				replacenumber++;
//			i++;
//		}
//		int newlength = oldnumber + replacenumber * 2;
//		int oldLen = oldnumber;
//		int newLen = newlength;
//		for (; oldLen >= 0 && oldLen < newLen; --oldLen)
//		{
//			if (str[oldLen] == ' ')
//			{
//				str[newLen--] = '0';
//				str[newLen--] = '2';
//				str[newLen--] = '%';
//			}
//			else
//				str[newLen--] = str[oldLen];
//		}
//	}
//};