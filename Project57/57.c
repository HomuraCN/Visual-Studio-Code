#include <stdio.h>

int main(void)
{
	char ISBN[14];
	char num[12];
	int j, k = 0, l, sum = 0, X;

	gets(ISBN);

	for (j = 0; j < 13; j++)
	{
		if (ISBN[j] == '-')
		{
			continue;
		}
		num[k] = ISBN[j];
		k++;
	}

	for (l = 0; l < 9; l++)
	{
		sum += (num[l] - 48) * (l + 1);
	}

	X = sum % 11;
	if (X == 10)
	{
		if(ISBN[12] == 'X')
		printf("Right");
		else
		{
			printf("%c-%c%c%c-%c%c%c%c%c-X", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8]);
		}
		return 0;
	}
	else if ((num[9] - 48) == X)
	{
		printf("Right");
	}
	else
	{
		{
			printf("%c-%c%c%c-%c%c%c%c%c-%d", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], X);
		}
	}
	
	return 0;
}