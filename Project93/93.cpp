#include <stdio.h>

int main()
{
	int n, counter = 0, flag = 0;
	char str[110];

	scanf("%d", &n);

	scanf("%s", str);

	if (n > 2)
	{
		for (int i = 1; i < n; i++)
		{
			if (str[i] == 'K' && str[i - 1] == 'V')
			{
				counter++;
				str[i] = '0';
				str[i - 1] = '0';
			}
		}
		for (int j = 1; j < n; j++)
		{
			if (str[j] == str[j - 1] && str[j-1] != '0')
			{
				flag = 1;
			}
		}
		printf("%d", counter + flag);
	}
	else if(n == 1)
	{
		printf("0");
	}
	else
	{
		if (str[0] == 'K' && str[1] == 'V')
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}

	return 0;
}