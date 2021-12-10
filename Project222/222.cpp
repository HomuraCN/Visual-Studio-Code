#include <stdio.h>
#include <string.h>

int main()
{
	int length, flag[110] = { 0 };
	char str[110];

	scanf("%s", str);

	length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] == ')')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (flag[j] == 0 && str[j] == '(')
				{
					flag[i] = 1, flag[j] = 1;
					break;
				}
				else if (flag[j] == 0 && str[j] == '[')
				{
					break;
				}
			}
		}
		else if (str[i] == ']')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (flag[j] == 0 && str[j] == '[')
				{
					flag[i] = 1, flag[j] = 1;
					break;
				}
				else if (flag[j] == 0 && str[j] == '(')
				{
					break;
				}
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		if (flag[i] == 1)
		{
			printf("%c", str[i]);
		}
		else
		{
			if (str[i] == '(' || str[i] == ')')
			{
				printf("()");
			}
			else
			{
				printf("[]");
			}
		}
	}

	return 0;
}