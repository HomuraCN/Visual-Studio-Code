#include <stdio.h>
#include <string.h>

typedef struct member
{
	char name[50];
	char position[50];
	int contribution;
	int rank;
}MEMBER;

int main()
{
	MEMBER member[120], temp;
	int n, a = 0, HuFa = 0, ZhangLao = 0, TangZhu = 0, JingYing = 0;
	char str[50] = { '\0' }, counter = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", member[i].name);
		scanf("%s", member[i].position);
		scanf("%d", &member[i].contribution);
		scanf("%d", &member[i].rank);
	}

	/*按帮贡排序*/
	for (int i = 3; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (member[i].contribution < member[j].contribution)
			{
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}

	/*重任命*/
	for (int i = 3; i < n; i++)
	{
		counter++;
		if (counter == 1 || counter == 2)
		{
			strcpy(member[i].position, str);
			strcpy(member[i].position, "HuFa");
		}
		if (counter == 3 || counter == 4 || counter == 5 || counter == 6)
		{
			strcpy(member[i].position, str);
			strcpy(member[i].position, "ZhangLao");
		}
		if (counter >= 7 && counter <= 13)
		{
			strcpy(member[i].position, str);
			strcpy(member[i].position, "TangZhu");
		}
		if (counter >= 14 && counter <= 38)
		{
			strcpy(member[i].position, str);
			strcpy(member[i].position, "JingYing");
		}
		if (counter >= 39)
		{
			strcpy(member[i].position, str);
			strcpy(member[i].position, "BangZhong");
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s %s %d", member[i].name, member[i].position, member[i].rank);
		printf("\n");
	}

	/*交换护法*/
	for (int i = 3; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (member[i].rank < member[j].rank)
			{
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}
	/*交换长老*/
	for (int i = 5; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (member[i].rank < member[j].rank)
			{
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}
	/*交换堂主*/
	for (int i = 9; i < 16; i++)
	{
		for (int j = i + 1; j < 16; j++)
		{
			if (member[i].rank < member[j].rank)
			{
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}
	/*交换精英*/
	for (int i = 16; i < 41; i++)
	{
		for (int j = i + 1; j < 41; j++)
		{
			if (member[i].rank < member[j].rank)
			{
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}
	/*交换帮众*/
	for (int i = 41; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (member[i].rank < member[j].rank)
			{
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s %s %d", member[i].name, member[i].position, member[i].rank);
		printf("\n");
	}

	return 0;
}