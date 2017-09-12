/*
��Ŀ����:���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
����4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool isPoprder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() == 0 || popV.size() == 0)
		return false;
		stack<int> stack;
		int popIndex = 0;
		for (int i = 0; i < pushV.size(); i++)
		{
			stack.push(pushV[i]);
			while (!stack.empty() && stack.top() == popV[popIndex])
			{
				stack.pop();
				popIndex++;
			}
		}
		return stack.empty();
	}
};