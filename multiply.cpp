/*
题目描述:给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

#include <vector>

using namespace std;

class Solution {
public:
	//function first
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		vector<int> forword(len, 0);
		vector<int> backword(len, 0);
		vector<int> res(len, 0);
		forword[0] = 1;
		backword[0] = 1;
		for (int i = 1; i < len; i++)
		{
			forword[i] = A[i - 1] * forword[i - 1];
			backword[i] = A[len - i] * backword[i - 1];
		}
		for (int i = 0; i < len; i++)
			res[i] = forword[i] * backword[len - i - 1];
		return res;
	}

	//function second
	vector<int> multiply2(const vector<int>& A) {
		int len = A.size();
		vector<int> res(len, 0);
		res[0] = 1;
		for (int i = 1; i < len; i++)
			res[i] = res[i - 1] * A[i - 1];
		int tmp = 1;
		for (int j = len - 2; j >= 0; j--)
		{
			tmp *= A[j + 1];
			res[j] *= tmp;
		}		
		return res;
	}
};