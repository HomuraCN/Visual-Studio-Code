#include <stdio.h>

int main()
{
	int year;

	printf("��������ݣ�");
	scanf_s("%d", &year);

	if (year % 4 == 0 && year % 100 != 0)
	{
		printf("����������\n");
	}
	else
	{
		printf("���겻������\n");
	}

	return 0;
}