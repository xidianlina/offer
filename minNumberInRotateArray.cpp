/*
��Ŀ����:��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
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