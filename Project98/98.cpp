#include <stdio.h>
#include <math.h>

void Absolution(int	L, int x, int y);

int mat[1025][1025];

int main()
{
	int n, L;

	scanf("%d", &n);

	L = pow(2 , n);

	for (int i = 1; i <= L; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			mat[i][j] = 1;
		}
	}

	Absolution(L, 1, 1);

	for (int i = 1; i <= L; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
/*ตÝน้:Absolution*/
void Absolution(int	L, int x, int y)
{
	if (L == 2)
	{
		mat[x][y] = 0;
		return;
	}
	for (int i = x; i <= x + L / 2 - 1; i++)
	{
		for (int j = y; j <= y + L / 2 -1; j++)
		{
			mat[i][j] = 0;
		}
	}
	Absolution(L / 2, L / 2 + x, y);
	Absolution(L / 2, L / 2 + x, L / 2 + y);
	Absolution(L / 2, x, L / 2 + y);
}