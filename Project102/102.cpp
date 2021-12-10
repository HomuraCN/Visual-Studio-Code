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
		/*����*/
		/*���� ��Խ��*/
		if (toy[flag].toward == 1 && (flag - commend[k].num) >= 0 && commend[k].lr == 1)
		{
			flag = flag - commend[k].num;
		}
		/*���� Խ��*/
		else if (toy[flag].toward == 1 && (flag - commend[k].num) < 0 && commend[k].lr == 1)
		{
			flag = flag - commend[k].num + n;
		}
		/*���� ��Խ��*/
		else if (toy[flag].toward == 1 && (flag + commend[k].num) <= n-1 && commend[k].lr == 0)
		{
			flag = flag + commend[k].num;
		}
		/*���� Խ��*/
		else if (toy[flag].toward == 1 && (flag + commend[k].num) > n-1 && commend[k].lr == 0)
		{
			flag = flag + commend[k].num - n;
		}
		/*����*/
		/*���� ��Խ��*/
		else if (toy[flag].toward == 0 && (flag + commend[k].num) <= n-1 && commend[k].lr == 1)
		{
			flag = flag + commend[k].num;
		}
		/*���� Խ��*/
		else if (toy[flag].toward == 0 && (flag + commend[k].num) >n-1 && commend[k].lr == 1)
		{
			flag = flag + commend[k].num - n;
		}
		/*���� ��Խ��*/
		else if (toy[flag].toward == 0 && (flag - commend[k].num) >= 0 && commend[k].lr == 0)
		{
			flag = flag - commend[k].num;
		}
		/*���� Խ��*/
		else if (toy[flag].toward == 0 && (flag - commend[k].num) < 0 && commend[k].lr == 0)
		{
			flag = flag - commend[k].num + n;
		}

	}

	printf("%s", toy[flag].name);

	return 0;
}