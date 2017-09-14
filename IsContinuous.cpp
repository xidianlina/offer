/*
��Ŀ���������˿��������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		int len = numbers.size();
		if (len != 5)
			return false;
		sort(numbers.begin(), numbers.end());
		int jokers = 0;//����������Ŀ 
		for (int i = 0; i < 5; i++)
			if (numbers[i] == 0)
				jokers++;
		for (int i = jokers + 1; i < 5; i++)
			if (numbers[i] == numbers[i - 1])//�ж϶��ӵĴ���
				return false;
		int dis = numbers[4] - numbers[jokers];
		if (dis <= 4)
			return true;
		return false;
	}
};