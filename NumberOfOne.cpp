/*
题目描述:输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

class Solution {
public:
	int NumberOfOne(int n) {
		int cnt = 0;
		unsigned int flag = 1;
		while (flag) {
			if (n&flag)
				cnt++;
			flag = flag << 1;
		}
		return cnt;
	}
	int NumberOf1(int n) {
		int cnt = 0;
		while (n) {
			cnt++;
			n = (n - 1)&n;
		}
		return cnt;
	}
};