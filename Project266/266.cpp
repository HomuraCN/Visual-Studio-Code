#include <stdio.h>
#include <string.h>

int T, a, b, sign, Min, temp, delta, MIN;
char str[30];

int main()
{
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d", &a, &b);
		scanf("%s", str);
		int len = strlen(str);
		Min = a * 60 + b;
		if (str[3] == '+')
		{
			sign = 1;
		}
		else
		{
			sign = -1;
		}
		if (len == 5)
		{
			temp = sign * (str[4] - '0') * 60;
			delta = temp - 480;
			MIN = (Min + delta) % (1440);
			printf("%02d:%02d\n", MIN < 0 ? (MIN + 1440) / 60, (MIN + 1440) % 60 : MIN / 60, MIN % 60);
		}
		else if (len == 6)
		{
			temp = sign * ((str[4] - '0') * 600 + (str[5] - '0') * 60);
			delta = temp - 480;
			MIN = (Min + delta) % (1440);
			printf("%02d:%02d\n", MIN < 0 ? (MIN + 1440) / 60, (MIN + 1440) % 60 : MIN / 60, MIN % 60);
		}
		else if (len == 7)
		{
			temp = sign * ((str[4] - '0') * 60 + (str[6] - '0') * 6);
			delta = temp - 480;
			MIN = (Min + delta) % (1440);
			printf("%02d:%02d\n", MIN < 0 ? (MIN + 1440) / 60, (MIN + 1440) % 60 : MIN / 60, MIN % 60);
		}
		else if (len == 8)
		{
			temp = sign * ((str[4] - '0') * 600 + (str[5] - '0') * 60 + (str[6] - '0') * 6);
			delta = temp - 480;
			MIN = (Min + delta) % (1440);
			printf("%02d:%02d\n", MIN < 0 ? (MIN + 1440) / 60, (MIN + 1440) % 60 : MIN / 60, MIN % 60);
		}
	}

	return 0;
}