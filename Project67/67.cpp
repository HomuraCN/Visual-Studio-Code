#include <stdio.h>

int GetMax(int a, int b);
int GetMin(int a, int b);


int main()
{
	int sort, i, a, b;
	int (*p)(int a, int b);

	scanf("%d %d %d", &i, &a, &b);

	if (i == 1)
	{
		p = GetMax;
	}
	else if (i == 2)
	{
		p = GetMin;
	}

	sort = (*p)(a, b);

	printf("%d", sort);

	return 0;
}

/*Max*/
int GetMax(int a, int b)
{
	int Max;

	Max = (a >= b) ? a : b;

	return Max;
}

/*Min*/
int GetMin(int a, int b)
{
	int Min;

	Min = (a <= b) ? a : b;

	return Min;
}