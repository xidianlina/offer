/*
��Ŀ����:��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

#include <iostream>
#include <vector>

class A {
public:
	A() :n2(0), n1(n2 + 2){}
	void print() {
		std::cout << "n1 = " << n1 << " n2 = " << n2 << std::endl;
	}

private :
	int n1;
	int n2;
};

int main() {
	int* p = new int[10];
	std::cout << sizeof(p) << std::endl;

	return 0;
}