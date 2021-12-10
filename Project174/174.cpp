#include <stdio.h>

long long w(int a, int b, int c);

long long Rec[21][21][21] = { 0 }, ans[21][4];

int main()
{
	long long a, b, c, cnt = 0;

	while (1)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}
		ans[cnt][0] = a;
		ans[cnt][1] = b;
		ans[cnt][2] = c;
		ans[cnt][3] = w(a, b, c);
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
	{
		printf("w(%lld, %lld, %lld) = %lld\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
	}

	return 0;
}
long long w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (Rec[a][b][c] != 0)
	{
		return Rec[a][b][c];
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		Rec[a][b][c] = w(20, 20, 20);
	}
	else if (a < b && b < c)
	{
		Rec[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		Rec[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

	return Rec[a][b][c];
}