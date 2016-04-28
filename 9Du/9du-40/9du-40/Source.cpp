#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int i, m, n;
	for (n = 1000; n<10000; n++)
	{
		i = n; m = 0;
		while (i)
		{
			m = m * 10 + i % 10;
			i = i / 10;
		}
		if (m == n * 9)
		{
			printf("%d\n", n);
		}
	}
	system("pause");
	return 0;
}