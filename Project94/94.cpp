#include <stdio.h>
#include <string.h>

int main()
{
	int length, flag = 0;
	char str1[100];

	scanf("%s", str1);

	length = strlen(str1);

	for (int i = 0; i < length; i++)
	{
		/*小数*/
		if (str1[i] == '.')
		{
			for (int j = i-1; j >=0; j--)
			{
				for(int a = j; a <i; a++)
				{
					if ((str1[j] == '0') && (str1[a + 1] == '0' || str1[a + 1] == '.'))
					{
						continue;
					}
					printf("%c", str1[j]);
					flag = 1;
					break;
				}
			}
			printf(".");
			for (int k = length - 1; k > i; k--)
			{
				for (int b = k; b > i; b--)
				{
					if ((str1[k] == '0') && (str1[b - 1] == '0' || str1[b - 1] == '.'))
					{
						continue;
					}
					printf("%c", str1[k]);
					flag = 1;
					break;
				}
			}
		}
		/*分数*/
		else if (str1[i] == '/')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				for (int a = j; a < i; a++)
				{
					if ((str1[j] == '0') && (str1[a + 1] == '0' || str1[a + 1] == '/'))
					{
						continue;
					}
					printf("%c", str1[j]);
					flag = 1;
					break;
				}
			}
			printf("/");
			for (int k = length - 1; k > i; k--)
			{
				for (int b = k; b > i; b--)
				{
					if ((str1[k] == '0') && (str1[b - 1] == '0' || str1[b - 1] == '/'))
					{
						continue;
					}
					printf("%c", str1[k]);
					flag = 1;
					break;
				}
			}
		}
		/*百分数*/
		else if (str1[i] == '%')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				for (int a = j; a < i; a++)
				{
					if ((str1[j] == '0') && (str1[a + 1] == '0' || str1[a + 1] == '%'))
					{
						continue;
					}
					printf("%c", str1[j]);
					flag = 1;
					break;
				}
			}
			printf("%%");
		}
	}

	/*整数*/
	if (flag == 0)
	{
		for (int j = length - 1; j >= 0; j--)
		{
			for (int a = j; a <= length - 1; a++)
			{
				if (str1[j] == '0' && str1[a] == '0')
				{
					continue;
				}
				printf("%c", str1[j]);
				break;
			}
		}
	}

	return 0;
}