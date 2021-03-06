/*
题目描述:输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
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