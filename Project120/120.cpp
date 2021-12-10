#include <stdio.h>
#include <string.h>

char num[21][10000], temp[100], temp1[100], temp2[100];

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", num[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			strcpy(temp1, num[j]);
			strcpy(temp2, num[j + 1]);
			if (strcmp(strcat(temp1, temp2), strcat(temp2, temp1)) < 0)
			{
				strcpy(temp, num[j]);
				strcpy(num[j], num[j + 1]);
				strcpy(num[j + 1], temp);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s", num[i]);
	}

	return 0;
}