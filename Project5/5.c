#include <stdio.h>

int main()
{
	int n;

	printf("������һ������:");
	scanf_s("%d", &n);

	if (n % 3 == 0, n % 5 == 0, n % 7 == 0)
	{
		printf("����������ͬʱ��3,5,7����\n");
	}
	else
	{
		printf("������������ͬʱ��3,5,7����\n");
	}

	return 0;
}