#include <stdio.h>

int main()
{
	int hun, ten, ind, num;

	printf("请输入一个三位数字:");
	scanf_s("%d", &num);

	hun = (num / 100) % 10;
	ten = (num / 10) % 10;
	ind = (num / 1) % 10;

	if (num == hun * hun * hun + ten * ten * ten + ind * ind * ind)
	{
		printf("这是水仙花数");
	}
	else
	{
		printf("这不是水仙花数");
	}

	return 0;
}