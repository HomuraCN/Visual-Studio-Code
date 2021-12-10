#include <stdio.h>

int main()
{
	char ch;
	int count = 0;

	printf("请输入一段信息:\n");

	do
	{
		count++;
		ch = getchar();
	} while (ch != '\n');

	count--;

	printf("此段信息的长度是:%d",count);

	return 0;
}