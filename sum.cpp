/*
��Ŀ����:��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/

#include <iostream>

using namespace std;

//function first  ���ù��캯�����
class Temp {
public:
public:
	Temp() 
	{
		++n;
		sum += n;
	}
	static void reset()
	{
		n = 0;
		sum = 0;
	}
	static unsigned int getSum()
	{
		return sum;
	}
private:
	static unsigned int n;
	static unsigned int sum;
};

unsigned int Temp::n = 0;
unsigned int Temp::sum = 0;

unsigned int sum(unsigned int n);
int Sum(int n);
unsigned int sum_solution(unsigned int n);
unsigned int sum_teminator(unsigned int n);
int sum4(int n);

int main()
{
	cout << sum(10) << endl;
	cout << Sum(10) << endl;
	cout << sum_solution(10) << endl;
	cout << sum4(10) << endl;
}

unsigned int sum(unsigned int n)
{
	Temp::reset();
	Temp *a = new Temp[n];
	delete[] a;
	a = NULL;
	return Temp::getSum();
}

//fuction second �����麯�����
//�����n���������η����㣬��!!n����ô�����nת��Ϊtrue��0ת��Ϊfalse��
class A;
A* Array[2];

class A {
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B :public A
{
public:
	virtual unsigned int Sum(unsigned int n)override
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(n);
	return value;
}

//functoin third ���ú���ָ�����
typedef unsigned int(*fun)(unsigned int);

unsigned int sum_teminator(unsigned int n)
{
	return 0;
}

unsigned int sum_solution(unsigned int n)
{
	static fun f[2] = { sum_teminator,sum_solution };
	return n + f[!!n](n - 1);
}

//function fourth
int sum4(int n)
{
	int sum = n;
	bool ans = (n > 0) && ((sum += sum4(n - 1)) > 0);
	return sum;
}