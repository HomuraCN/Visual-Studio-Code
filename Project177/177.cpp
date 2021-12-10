#include <stdio.h>
#include <math.h>

void Rec(int n);

int main()
{
	int n;

	scanf("%d", &n);

	Rec(n);

	return 0;
}
void Rec(int n)
{
	for (int i = 15; i >= 0; i--)
	{
		if (n != 0 && n >= pow(2, i))
		{
			if (i == 1)
			{
				printf("2");
			}
			else if (i == 0)
			{
				printf("2(0)");
			}
			else
			{
				printf("2(");
				Rec(i);
				printf(")");
			}
			n -= pow(2, i);
			if (n != 0)
			{
				printf("+");
			}
		}
	}
}