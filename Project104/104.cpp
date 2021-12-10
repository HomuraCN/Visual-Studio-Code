#include <stdio.h>
#include <string.h>

int main()
{
	char str1[2020], str2[2020];
	int num1[2020], num2[2020], num3[4050] = { 0 }, len, len1, len2, lenmax;

	scanf("%s %s", str1, str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	lenmax = len1 >= len2 ? len1 : len2;

	for (int i = 1; i <= len1; i++)
	{
		num1[i] = str1[len1 - i] - 48;
	}
	for (int j = 1; j <= len2; j++)
	{
		num2[j] = str2[len2 - j] - 48;
	}

	for (int i = 1; i <= len2; i++)
	{
		for (int j = 1; j <= len1; j++)
		{
			num3[i + j - 1] += num2[i] * num1[j];
		}
	}

	for (int k = 1; k <= len2 + len1; k++)
	{
		if (num3[k] >= 10)
		{
			num3[k + 1] += num3[k] / 10;
			num3[k] %= 10;
		}
	}

	len = len1 + len2;

	while (num3[len] == 0 && len > 1)
	{
		len--;
	}

	for (int p = len; p > 0; p--)
	{
		printf("%d", num3[p]);
	}

	return 0;
}