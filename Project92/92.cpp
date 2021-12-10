#include <stdio.h>
#include <string.h>


int main()
{
	
	int length1, length2, counter = 0, flag = 0, point[100000] = { -1 }, a = 0;
	char str1[11], str2[100005], str[100009] = { ' ' };

	scanf("%s", str1);
	getchar();
	gets_s(str2);

	strcat(str, str2);

	length1 = strlen(str1);
	length2 = strlen(str);

	/*小写字母化为大写字母*/
	for (int i = 0; i < length1; i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			str1[i] -= 32;
		}
	}

	for (int j = 0; j < length2; j++)
	{
		if (str[j] >= 'a' && str[j] <= 'z')
		{
			str[j] -= 32;
		}
	}

	/*查找个数*/
	for (int k = 0; k < length2; k++)
	{
		int m = 0;

		if (flag == 1)
		{
			counter++;
		}

		flag = 0;

		if (str[k] == str1[0])
		{
			if (str[k - 1] == ' ' && str[k + length1] == ' ')
			{
				for (int h = k; h < k + length1; h++)
				{
					if (str[h] == str1[m++])
					{
						flag = 1;
						point[a++] = h - 1;
					}
					else
					{
						flag = 0;
						point[--a] = -1;
					}
				}
			}
		}
	}

	if (counter > 0)
	{
		printf("%d ", counter);
	}

	/*定位*/
	if (point[0] != -1)
	{
		printf("%d", point[0]);
	}
	else
	{
		printf("-1");
	}

	return 0;
}