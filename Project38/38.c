#include <stdio.h>

int main()
{
	int m, s, t;

	scanf_s("%d %d %d", &m, &t, &s);
	if(t == 0)
	{
		printf("%d", 0);
	}
	else if (s % t == 0 && (m - s / t >= 0))
	{
		printf("%d", m - s / t);
	}
	else if(s % t != 0 && (m - s / t >= 0))
	{
		printf("%d", (m - s / t) - 1);
	}
	else if (s % t != 0 && (m - s / t < 0))
	{
		printf("%d", 0);
	}
	else if(s % t == 0 && (m - s / t < 0))
	{
		printf("%d", 0);
	}

	return 0;
}