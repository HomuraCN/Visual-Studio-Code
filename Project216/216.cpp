#include <stdio.h>
#include <string.h>
#include <math.h>

void Exchenge(int n, int m, char str[], char str1[], char str2[]);
int flag = 1;

int main()
{
	int n, m;
	char str[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }, str1[32], str2[33], str3[33];

	scanf("%s", str1);

	for (int i = 0; i < 33; i++)
	{
		str2[i] = '0';
	}

	Exchenge(10, 2, str, str1, str2);

	for (int i = 0; i < 16; i++)
	{
		char temp;
		temp = str2[i];
		str2[i] = str2[31 - i];
		str2[31 - i] = temp;
	}

	for (int i = 0; i < 16; i++)
	{
		char temp;
		temp = str2[i];
		str2[i] = str2[16 + i];
		str2[16 + i] = temp;
	}

	Exchenge(2, 10, str, str2, str3);

	return 0;
}
void Exchenge(int n, int m, char str[], char str1[], char str2[])
{
	int length = strlen(str1), sum = 0, cnt = 0;
	if (flag == 0)
	{
		length = 32;
	}
	for (int i = 0; i < length; i++)
	{
		if (str1[length - 1 - i] >= '0' && str1[length - 1 - i] <= '9')
		{
			sum += (str1[length - 1 - i] - '0') * pow(n, i);
		}
		else
		{
			sum += (str1[length - 1 - i] - 55) * pow(n, i);
		}
	}
	while (sum > 0)
	{
		int r = sum % m;
		sum /= m;
		str2[cnt++] = str[r];
	}
	if (flag == 0)
	{
		for (int i = cnt - 1; i >= 0; i--)
		{
			printf("%c", str2[i]);
		}
	}
	flag = 0;
}