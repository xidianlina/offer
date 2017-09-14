/*
题目描述:求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

#include <iostream>

using namespace std;

//function first  利用构造函数求解
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

//fuction second 利用虚函数求解
//如果对n连续做两次反运算，即!!n，那么非零的n转换为true，0转换为false。
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

//functoin third 利用函数指针求解
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