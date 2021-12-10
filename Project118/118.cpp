#include <stdio.h>
#include <string.h>

typedef struct pre
{
	int id;
	char num[110];
	int length;
}PRE;

int main()
{
	PRE pre[20], temp;
	int n, max = 0;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", pre[i].num);
		pre[i].length = strlen(pre[i].num);
		pre[i].id = i + 1;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (pre[j].length < pre[j + 1].length)
			{
				temp = pre[j];
				pre[j] = pre[j + 1];
				pre[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (pre[j].length == pre[j + 1].length && strcmp(pre[j].num, pre[j + 1].num) < 0)
			{
				temp = pre[j];
				pre[j] = pre[j + 1];
				pre[j + 1] = temp;
			}
		}
	}

	printf("%d\n%s", pre[0].id, pre[0].num);

	return 0;
}