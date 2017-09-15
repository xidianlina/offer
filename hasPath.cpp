/*
��Ŀ����:�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� 
���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
*/

#include <vector>

using namespace std;

class Solution {
	bool hasPathRecu(char* matrix, int rows, int cols, int row, int col, char *str, int length, vector<bool> used)
	{
		if (length == strlen(str))
			return true;
		if (row<0 || row >= rows || col<0 || col >= cols)
			return false;
		int index = col + row*cols;
		bool result = false;
		if (!used[index] && matrix[index] == str[length]) {
			used[index] = true;
			result = hasPathRecu(matrix, rows, cols, row - 1, col, str, length + 1, used) || hasPathRecu(matrix, rows, cols, row + 1, col, str, length + 1, used)
				|| hasPathRecu(matrix, rows, cols, row, col + 1, str, length + 1, used) || hasPathRecu(matrix, rows, cols, row, col - 1, str, length + 1, used);
			used[index] = false;
		}
		if (result)
			return true;
		return false;
	}
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		vector<bool> used(strlen(matrix), false);
		if (str == NULL) return true;
		for (int i = 0; i<rows; i++) {
			for (int j = 0; j<cols; j++) {
				if (hasPathRecu(matrix, rows, cols, i, j, str, 0, used))
					return true;
			}
		}
		return false;
	}
};