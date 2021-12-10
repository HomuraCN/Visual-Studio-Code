#include <stdio.h>
#define N 50

int GetScore(int score[], long number[]);
int LinearSearch(long number[], long x, int num);

int main(void)
{
	int score[N], num, pos;
	long x, number[N];

	num = GetScore(score, number);
	scanf_s("%ld", &x);
	pos = LinearSearch(number, x, num);
	
	if (pos != -1)
	{
		printf("score = %4d\n", score[pos]);
	}
	else
	{
		printf("404 Not found!\n");
	}

	return 0;
}

/*键入成绩和学号*/
int GetScore(int score[], long number[])
{
	int i = -1;
	do
	{
		i++;
		scanf_s("%ld %d", &number[i], &score[i]);
	} while (score[i] >= 0 && number[i] > 0);

	return i;
}

/*遍历查找*/
int LinearSearch(long number[], long x, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (number[i] == x)
		{
			return i;
		}
		
		return -1;
	}
}