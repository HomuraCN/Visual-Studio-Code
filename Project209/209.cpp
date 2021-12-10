#include <stdio.h>

int n, cnt = 0, ans[15], line[15] = { 0 }, northwest_southeast[30] = { 0 }, northeast_southwest[30] = { 0 };

void DFS(int i);
void Print_Cnt(void);

int main()
{
	scanf("%d", &n);

	DFS(1);

	printf("%d", cnt);

	return 0;
}
/*标记，记录皇后位置*/
void DFS(int i)
{
	if (i > n)
	{
		Print_Cnt();
		return;
	}
	else
	{
		for (int j = 1; j <= n; j++)/*行*/
		{
			if (northeast_southwest[i + j] == 0 && northwest_southeast[i - j + n] == 0 && line[j] == 0)
			{
				ans[i] = j;
				line[j] = 1;
				northeast_southwest[i + j] = 1;
				northwest_southeast[i - j + n] = 1;
				DFS(i + 1);
				line[j] = 0;
				northeast_southwest[i + j] = 0;
				northwest_southeast[i - j + n] = 0;
			}
		}
	}
}
void Print_Cnt(void)
{
	cnt++;
	if (cnt <= 3)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return;
}