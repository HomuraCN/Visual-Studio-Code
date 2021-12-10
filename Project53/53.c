#include <stdio.h>
#define N 50

int GetScore(int score[]);
void SortScore(int score[], int num);
void PrintScore(int score[], int num);

int main(void)
{
	int score[N], num;

	num = GetScore(score);
	SortScore(score, num);
	PrintScore(score, num);

	return 0;
}

/*输入学生成绩*/
int GetScore(int score[])
{
	int i = -1;
	do
	{
		i++;
		scanf_s("%d", &score[i]);
	} while (score[i] >= 0);

	return i;
}

/*成绩排序*/
void SortScore(int score[], int num)
{
	int i, j, temp;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 -i; j++)
		{
			if (score[j] > score[j+1])
			{
				temp = score[j];
				score[j] = score[j+1];
				score[j+1] = temp;
			}
		}
	}
}

/*成绩打印*/
void PrintScore(int score[], int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		printf("%d ", score[i]);
	}
}