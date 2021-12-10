#include <stdio.h>

int main(void)
{
	int n, sum = 0;

	printf("请输入若干整数:");

	while (scanf_s("%d", &n))
	{
		if (n % 2 == 0)
		{
			sum = sum + n;
		}
	}

	printf("其中所有偶数的和是:%d", sum);

	return 0;
}