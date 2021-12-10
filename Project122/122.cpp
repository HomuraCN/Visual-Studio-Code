#include <stdio.h>

void Rec(int n, int cnt, int num[], int is[]);

int main()
{
	int n, num[9], is[10] = { 0 }/*哪几个数在栈内*/;

	scanf("%d", &n);

	Rec(n, 0, num, is);

	return 0;
}
/*递归*/
void Rec(int n, int cnt, int num[], int is[])
{
	if (cnt == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%5d", num[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (is[i] == 0)
			{
				num[cnt] = i;
				is[i] = 1;
				Rec(n, cnt + 1, num, is);
				is[i] = 0;
			}
		}
	}
}