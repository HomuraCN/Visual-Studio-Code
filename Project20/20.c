#include <stdio.h>

int main()
{
	char ch;
	int count = 0;

	printf("������һ����Ϣ:\n");

	do
	{
		count++;
		ch = getchar();
	} while (ch != '\n');

	count--;

	printf("�˶���Ϣ�ĳ�����:%d",count);

	return 0;
}