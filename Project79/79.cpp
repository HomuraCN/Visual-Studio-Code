#include <stdio.h>

int main()
{
	int n, m, num[100], i = -1;

	do
	{
		printf("������һ��ʮ��������<-1��������>:");
		scanf("%d", &n);

		if (n == -1)
		{
			return 0;
		}

		printf("������Ҫת���ɵĽ���:");
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