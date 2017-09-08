/*
题目描述:把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include <iostream>

class Solution{
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
        int low=0;
		int high=rotateArray.size()-1;
		int mid=low;
		while(rotateArray[low]>=rotateArray[high]){
			if(high-low==1){
				mid=high;
				break;
			}
			mid=(low+high)/2;
			if(rotateArray[low]==rotateArray[high]&&rotateArray[mid]==rotateArray[low]){
				return minInOrder(rotateArray,low,high);
			}
			if(rotateArray[mid]>=rotateArray[low])
				low=mid;
			else if(rotateArray[mid]<=rotateArray[high])
				high=mid;
		}
		return rotateArray[mid];
    }
	int minInOrder(vector<int> vec,int low,int high){
		int min=vec[low];
		for(int i=low+1;i<=high;i++){
			if(min>vec[i])
				min=vec[i];
		}
		return min;
	}
};