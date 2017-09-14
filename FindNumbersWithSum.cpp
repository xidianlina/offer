/*
��Ŀ����:����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S��
����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
*/

#include <vector>

using namespace std;

class Solution {
public:
	/*
	�������������������ͷβ����ָ��i��j��
	��ai + aj == sum�����Ǵ𰸣����ԽԶ�˻�ԽС��
	��ai + aj > sum��aj�϶����Ǵ�֮һ��ǰ���ѵó� i ǰ��������ǲ����ܣ���j -= 1
	��ai + aj < sum��ai�϶����Ǵ�֮һ��ǰ���ѵó� j ����������ǲ����ܣ���i += 1 
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