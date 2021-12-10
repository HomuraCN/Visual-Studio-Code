#include <stdio.h>

int main()
{
	char str[4];
	int num[3], temp;

	for (int k = 0; k < 3; k++)
	{
		scanf("%d", &num[k]);
	}

	scanf_s(" %s", str);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2 - i; j++)
		{
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	if (str  == "ABC")
	{
		printf("%d%d%d", num[0], num[1], num[2]);
	}
	else if (str == "ACB")
	{
		printf("%d%d%d", num[0], num[2], num[1]);
	}
	else if (str == "BAC")
	{
		printf("%d%d%d", num[1], num[0], num[2]);
	}
	else if (str == "BCA")
	{
		printf("%d%d%d", num[1], num[2], num[0]);
	}
	else if (str == "CAB")
	{
		printf("%d%d%d", num[2], num[0], num[1]);
	}
	else if (str == "CBA")
	{
		printf("%d%d%d", num[2], num[1], num[0]);
	}
	
	return 0;
}