/*
��Ŀ����:������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� 
���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38����
��Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
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