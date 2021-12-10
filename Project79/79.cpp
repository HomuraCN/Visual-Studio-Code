#include <stdio.h>

int main()
{
	int n, m, num[100], i = -1;

	do
	{
		printf("请输入一个十进制整数<-1结束输入>:");
		scanf("%d", &n);

		if (n == -1)
		{
			return 0;
		}

		printf("请输入要转换成的进制:");
		scanf("%d", &m);

		if (n == 2)
		{
			while (n != 0)
			{
				i++;
				num[i] = n % 2;
			}
		}

	} while (1);
	

	return 0;
}