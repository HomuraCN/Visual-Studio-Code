#include <stdio.h>
#include <string.h>

int main()
{
	char str1[510], str2[510];
	int num1[520] = { 0 }, num2[520] = { 0 }, num3[520], len1, len2, lenmax, r = 0;

	scanf("%s", str1);
	scanf("%s", str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	lenmax = len1 >= len2 ? len1 : len2;

	for (int i = 0; i < len1; i++)
	{
		num1[len1 - i] = str1[i] - 48;
	}
	for (int j = 0; j < len2; j++)
	{
		num2[len2 - j] = str2[j] - 48;
	}

	for (int j = 1; j <= lenmax; j++)
	{
		num3[j] = num1[j] + num2[j] + r;
		r = num3[j] / 10;
		num3[j] %= 10;
	}
	if (r != 0)
	{
		num3[++lenmax] = r;
	}

	for (int k = lenmax; k > 0; k--)
	{
		printf("%d", num3[k]);
	}

	return 0;
}