/*
��Ŀ����:һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
*/

class Solution {
public:
	int jumpFloorII(int target) {
		if (target <= 0)
			return 0;
		if (target == 1)
			return 1;
		int res = 1;
		for (int i = 1; i < target; i++)
			res+=jumpFloorII(target - i);
		return res;
	}
};