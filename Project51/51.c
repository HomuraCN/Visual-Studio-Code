#include <stdio.h>
#define N 50

int GetScore(int score[]);
float GetAverage(int score[], int num);
int GetMax(int score[], int num);
int GetMin(int score[], int num);

int main(void)
{
	int score[N], num, max, min;
	float average;

	num = GetScore(score);
	average = GetAverage(score, num);
	max = GetMax(score, num);
	min = GetMin(score, num);

	printf("The number of effect grades is:%d\n", num);
	printf("The average is:%.2f\n", average);
	printf("The max is:%d\n", max);
	printf("The min is:%d\n", min);

	return 0;
}

/*输入各个学生成绩*/
int GetScore(int score[])
{
	int i = -1;
	printf("Enter score(s):");
	do
	{
		i++;
		scanf_s("%d", &score[i]);
	} while (score[i] >= 0);

	return i;
}

/*计算成绩平均分*/
float GetAverage(int score[], int num)
{
	float average;
	int i, sum = 0;

	for (i = 0; i < num; i++)
	{
		sum += score[i];
		average = (1.0 * sum) / num;
	}

	return  num > 0 ? average : -1;
}

/*取得最高分*/
int GetMax(int score[], int num)
{
	int max = 0, i;

	for (i = 0; i < num; i++)
	{
		if (score[i] > max)
		{
			max = score[i];
		}

	}

	return max;
}

/*取得最低分*/
int GetMin(int score[], int num)
{
	int min = score[0], i;

	for (i = 1; i < num; i++)
	{
		if (score[i] < min)
		{
			min = score[i];
		}

	}

	return min;
}