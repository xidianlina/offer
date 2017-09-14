/*
题目描述：从扑克中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2—10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看出任意数字。
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
		int jokers = 0;//计算王的数目 
		for (int i = 0; i < 5; i++)
			if (numbers[i] == 0)
				jokers++;
		for (int i = jokers + 1; i < 5; i++)
			if (numbers[i] == numbers[i - 1])//判断对子的存在
				return false;
		int dis = numbers[4] - numbers[jokers];
		if (dis <= 4)
			return true;
		return false;
	}
};