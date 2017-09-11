#include<iostream>

using namespace std;

void MergeArray(int a[], int alen, int b[], int blen)
{
	int len = alen + blen - 1;
	alen--;
	blen--;
	while (alen >= 0 && blen >= 0)
	{
		if (a[alen]>b[blen])
		{
			a[len--] = a[alen--];
		}
		else {
			a[len--] = b[blen--];
		}
	}
	while (blen >= 0)
	{
		a[len--] = b[blen--];
	}
}