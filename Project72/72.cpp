#include <stdio.h>

void PrintRectangle(int n);
void	PrintTangle(int n);

int main()
{
	int n;
	
	scanf("%d", &n);

	PrintRectangle(n);

	printf("\n");

	PrintTangle(n);

	return 0;
}

/*打印正方形*/
void PrintRectangle(int n)
{

	for (int i = 1; i <= n*n; i++)
	{
		printf("%02d", i);
		if (i % n == 0)
		{
			printf("\n");
		}
	}
}

/*打印三角形*/
void PrintTangle(int n)
{
	int counter = 0;

	for (int i = 1; i <= (n * (1 + n) / 2); i++)
	{
		
		if (i == 1 || i == 2 || i == 4 || i == 7 || i == 11 || i == 16 || i == 22 || i == 29 || i == 37)
		{
			for (int j = (n - 1) * 2 - counter; j > 0; j--)
			{
				printf(" ");
			}
		}

		printf("%02d", i);

		if(i == 1 || i == 3 || i == 6 || i == 10 || i == 15 || i == 21 || i == 28 || i == 36 || i == 45)
		{
			printf("\n");
			counter += 2;
		}
	}
}