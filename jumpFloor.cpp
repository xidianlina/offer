/*
题目描述:一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

class Solution {
public:
	int jumpFloor(int num) {
		if (num == 1)
			return 1;
		if (num == 2)
			return 2;
		return jumpFloor(num - 1) + jumpFloor(num - 2);
	}
	int jumpFloor(int number) {
		if (number <= 0) {
			return 0;
		}
		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		int first = 1, second = 2, res = 0;
		for (int i = 3; i <= number; i++) {
			res = first + second;
			first = second;
			second = res;
		}
		return res;
	}
};