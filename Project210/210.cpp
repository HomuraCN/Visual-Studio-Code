#include <stdio.h>

int min = 2000000000;

void DFS(int i, int j, int left, int right, int s[], int t[][21]);
int Max(int x, int y);
int Min(int x, int y);

int main()
{
	int ans = 0, T = 0, s[5], t[5][21];

	for (int i = 1; i <= 4; i++)
	{
		scanf("%d", &s[i]);
	}

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= s[i]; j++)
		{
			scanf("%d", &t[i][j]);
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		min = 2000000000;
		int left = 0, right = 0;
		DFS(i, 1, left, right, s, t);
		T += min;
	}

	printf("%d", T);

	return 0;
}
void DFS(int i, int j, int left, int right, int s[], int t[][21])
{
	if (j > s[i])
	{
		min = Min(min, Max(left, right));
		return;
	}
	else
	{
		/*加到左脑*/
		left += t[i][j];
		DFS(i, j + 1, left, right, s, t);
		left -= t[i][j];
		/*加到右脑*/
		right += t[i][j];
		DFS(i, j + 1, left, right, s, t);
		right -= t[i][j];	
		return;
	}
}
int Max(int x, int y)
{
	return x >= y ? x : y;
}
int Min(int x, int y)
{
	return x <= y ? x : y;
}