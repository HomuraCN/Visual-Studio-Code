#include <stdio.h>

int main(void)
{
	int n, sum = 0;

	printf("��������������:");

	while (scanf_s("%d", &n))
	{
		if (n % 2 == 0)
		{
			sum = sum + n;
		}
	}

	printf("��������ż���ĺ���:%d", sum);

	return 0;
}