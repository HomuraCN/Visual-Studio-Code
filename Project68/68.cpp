#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char num[11];

	scanf("%s", num);

	if (num[0] == '-')
	{
		printf("-");
		for (i = strlen(num) - 1; i > 0; i--)
		{
			if (num[i] != 0)
			{
				break;
			}
		}
		for ( ; i > 0; i--)
		{
			printf("%c", num[i]);
		}
	}
	else
	{
		for (i = strlen(num); i > 0; i--)
		{
			if (num[i] == 0)
			{
				break;
			}
		}
		for (; i > 0; i--)
		{
			printf("%c", num[i]);
		}
	}

	return 0;
}