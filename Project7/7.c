#include <stdio.h>

int main()
{
	int h, count, flag = 1;

	printf("������һ������:");
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
		printf("������������");
	}
	else
	{
		printf("��������������");
	}

	return 0;
}