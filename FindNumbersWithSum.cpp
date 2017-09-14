/*
题目描述:输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

#include <vector>

using namespace std;

class Solution {
public:
	/*
	数列满足递增，设两个头尾两个指针i和j，
	若ai + aj == sum，就是答案（相差越远乘积越小）
	若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
	若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1 
	*/
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int len = array.size();
		vector<int> res;
		if (len < 2)
			return res;
		int left = 0;
		int right = len - 1;
		while (left < right)
		{
			int curSum = array[left] + array[right];
			if (curSum == sum)
			{
				res.push_back(array[left]);
				res.push_back(array[right]);
				break;
			}
			else if (curSum > sum)
				right--;
			else
				left++;
		}
		return res;
	}
};