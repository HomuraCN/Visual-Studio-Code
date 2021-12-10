#include <stdio.h>

int main()
{
	int n;

	printf("请输入一个整数:");
	scanf_s("%d", &n);

	if (n % 3 == 0, n % 5 == 0, n % 7 == 0)
	{
		printf("此整数可以同时被3,5,7整除\n");
	}
	else
	{
		printf("此整数不可以同时被3,5,7整除\n");
	}

	return 0;
}