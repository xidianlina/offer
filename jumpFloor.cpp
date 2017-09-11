/*
��Ŀ����:һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
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