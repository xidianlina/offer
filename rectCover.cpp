/*
题目描述:我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
	int rectCover(int number) {
		if (number == 0)return 0;
		if (number == 1)return 1;
		if (number == 2) return 2;
		int a[3];
		a[1] = 1;
		a[2] = 2;
		for (int i = 3; i <= number; i++) {
			int f = a[1] + a[2];
			a[1] = a[2];
			a[2] = f;
		}
		return a[2];
	}
};