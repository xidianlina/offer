/*
��Ŀ����:HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:
�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��᲻�ᱻ������ס��(�������ĳ���������1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> arr)
	{
		if (arr.empty() || arr.size() == 0)
			return -1;
		int curSum = arr[0];
		int maxSum = arr[0];
		for (int i = 1; i < arr.size(); i++)
		{
			if (curSum <= 0)
				curSum = arr[i];
			else
				curSum += arr[i];
			if (curSum > maxSum)
				maxSum = curSum;
		}
		return maxSum;
	}
};