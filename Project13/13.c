#include <stdio.h>

int main()
{
	int m, n, r;

	printf("请输入m:\n");
	scanf_s("%d", &m);
	printf("请输入n:\n");
	scanf_s("%d", &n);

	r = m % n;

	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}

	printf("m和n的最大公约数是:%d", n);

	return 0;
}