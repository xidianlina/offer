/*
��Ŀ����:���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
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