#include <stdio.h>

int main()
{
	int h, count, flag = 1;

	printf("请输入一个整数:");
	scanf_s("%d", &h);

	for (count = 2; count < h; count++)
	{
		if (h % count == 0)
		{
			flag = 0;
			break;
		}
	}

	if (flag == 1)
	{
		printf("此整数是质数");
	}
	else
	{
		printf("此整数不是质数");
	}

	return 0;
}