#include <iostream>
#include <vector>

class Solution {
public:
	bool Find(int target, std::vector<std::vector<int>> array)
	{
		int row = array.size();
		int col = array[0].size();
		int i = 0;
		int j = col - 1;
		while (i < row&&j >= 0)
		{
			if (target > array[i][j])
			{
				i++;
			}
			else if (target < array[i][j])
			{
				j--;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};