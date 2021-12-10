#include <stdio.h>

typedef struct toy
{
	int toward;
	char name[20];
}TOY;

typedef struct commend
{
	int lr;
	int num;
}COMMEND;

TOY toy[100001];
COMMEND commend[100001];

int main()
{
	int n, m, flag = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &toy[i].toward, toy[i].name);
	}

	for (int j = 0; j < m; j++)
	{
		scanf("%d %d", &commend[j].lr, &commend[j].num);
	}

	for (int k = 0; k < m; k++)
	{
		/*朝外*/
		/*朝右 不越界*/
		if (toy[flag].toward == 1 && (flag - commend[k].num) >= 0 && commend[k].lr == 1)
		{
			flag = flag - commend[k].num;
		}
		/*朝右 越界*/
		else if (toy[flag].toward == 1 && (flag - commend[k].num) < 0 && commend[k].lr == 1)
		{
			flag = flag - commend[k].num + n;
		}
		/*朝左 不越界*/
		else if (toy[flag].toward == 1 && (flag + commend[k].num) <= n-1 && commend[k].lr == 0)
		{
			flag = flag + commend[k].num;
		}
		/*朝左 越界*/
		else if (toy[flag].toward == 1 && (flag + commend[k].num) > n-1 && commend[k].lr == 0)
		{
			flag = flag + commend[k].num - n;
		}
		/*朝内*/
		/*朝右 不越界*/
		else if (toy[flag].toward == 0 && (flag + commend[k].num) <= n-1 && commend[k].lr == 1)
		{
			flag = flag + commend[k].num;
		}
		/*朝右 越界*/
		else if (toy[flag].toward == 0 && (flag + commend[k].num) >n-1 && commend[k].lr == 1)
		{
			flag = flag + commend[k].num - n;
		}
		/*朝左 不越界*/
		else if (toy[flag].toward == 0 && (flag - commend[k].num) >= 0 && commend[k].lr == 0)
		{
			flag = flag - commend[k].num;
		}
		/*朝左 越界*/
		else if (toy[flag].toward == 0 && (flag - commend[k].num) < 0 && commend[k].lr == 0)
		{
			flag = flag - commend[k].num + n;
		}

	}

	printf("%s", toy[flag].name);

	return 0;
}