#include <stdio.h>

int main()
{
	int m, n, r;

	printf("������m:\n");
	scanf_s("%d", &m);
	printf("������n:\n");
	scanf_s("%d", &n);

	r = m % n;

	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}

	printf("m��n�����Լ����:%d", n);

	return 0;
}