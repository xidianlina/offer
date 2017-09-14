/*
题目描述:请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
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
				三种可能：
				1、模式串当前字符出现0次，即*表示当前字符出现0次，则str=str,pattern=pattern+2;
				2、模式串当前字符出现1次，即*表示当前字符出现1次，则str=str+1,pattern=pattern+2;
				3、模式串当前字符出现2次或2次以上，即*表示当前字符出现2次或以上，则str=str+1,pattern=pattern;
				*/
				return match(str, pattern + 2) || match(str + 1, pattern) || match(str + 1, pattern + 2);
			else
				/*
				排除特例：a和a*a
				由于后面还有一个a所以前面a*需要当作 "0",就算str[]和pattern[]相等,也得舍去，看作不相同
				所以match(str,pattern+2)这句也需要加上				
				*/
				return match(str, pattern + 2);
		}
	}
};