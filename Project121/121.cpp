#include <stdio.h>

void Rec(int n, int r, int cnt, int origin, int end);

int num[3];

int main()
{
	int n, r;

	scanf("%d %d", &n, &r);

	Rec(n, r, 0, 1, n - r + 1);

	return 0;
}

void Rec(int n, int r, int cnt, int origin, int end)
{
	if (cnt == r)
	{
		for (int i = 0; i < r; i++)
		{
			printf("%3d", num[i]);
		}
		printf("\n");
		return;
	}

	for (int i = origin; i <= end; i++)
	{
		num[cnt] = i;
		Rec(n, r, cnt + 1, i + 1, end + 1);
	}
	return;
}