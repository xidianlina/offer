/*
题目描述:地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

#include <vector>

using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols) {
		if (rows <= 0 || cols <= 0 || threshold <= 0) 
			return 0;
		int * res = new int[rows * cols];
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				res[i * cols + j] = 0;
			}
		}
		int cnt = 0;
		if (check(threshold, 0, 0)) {
			res[0] = 1;
			++cnt;
		}
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (((i >= 1 && res[(i - 1) * cols + j]) ||
					(j >= 1 && res[i * cols + j - 1])) &&
					check(threshold, i, j)) {
					res[i * cols + j] = 1;
					++cnt;
				}
			}
		}
		return cnt;
	}

	bool check(int threshold, int x, int y) {
		int sum = 0;
		while (x != 0) {
			sum += x % 10;
			x = x / 10;
		}
		while (y != 0) {
			sum += y % 10;
			y = y / 10;
		}
		return threshold >= sum;
	}
};