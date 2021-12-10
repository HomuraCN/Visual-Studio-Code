#include <stdio.h>
#define M 50
#define N 5

void ReadScore(int a[][N], long num[], int n);
void AverforStud(int a[][N], int sum[], float aver[], int n);
void AverforCourse(int a[][N], int sum[], float aver[], int n);
void Print(int a[][N], long num[], int sum1[], float aver1[], int sum2[], float aver2[], int n);

int main(void)
{
	int a[M][N], sum1[M], sum2[N], n;
	long num[M];
	float aver1[M], aver2[N];
	printf("Input total students:");
	scanf_s("%d", &n);
	ReadScore(a, num, n);
	AverforStud(a, sum1, aver1, n);
	AverforCourse(a, sum2, aver2, n);
	printf(a, num, sum1, aver1, sum2, aver2, n);

	return 0;
}

/*输入n个学生的学号及5门课的成绩*/
void ReadScore(int a[][N], long num[], int n)
{
	int i, j;
	printf("Input student's ID & score as: MT EN CP DS SE:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%ld", &num[i]);
		for (j = 0; j < N; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}

/*计算每个学生的总分和平均分*/
void AverforStud(int a[][N], int sum[], float aver[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		sum[i] = 0;
		for (j = 0; j < N; j++)
		{
			sum[i] = sum[i] + a[i][j];
		}
		aver[i] = (float)sum[i] / N;
	}
}

/*计算每门课的总分和平均分*/
void AverforCourse(int a[][N], int sum[], float aver[], int n)
{
	int i, j;
	for (j = 0; j < N; j++)
	{
		sum[j] = 0;
		for (i = 0; i < n; i++)
		{
			sum[j] = sum[j] + a[i][j];
		}
		aver[j] = (float)sum[j] / n;
	}
}

/*打印每个学生的学号、各门课的成绩、总分和平均分，及每门课的总分和平均分*/
void Print(int a[][N], long num[], int sum1[], float aver1[], int sum2[], float aver2[], int n)
{
	int i, j;
	printf("ID & score\t: MT\t EN\t CP\t DS\t SE\t SUM\t AVER\t:\n");
	for (i = 0; i < n; i++)
	{
		printf("%10ld\t", num[i]);
		for (j = 0; j < N; j++)
		{
			printf("%4d\t", a[i][j]);
		}
		printf("%4d\t%5.1f\n", sum1[i], aver1[i]);
	}
	printf("SumofCourse\t");
	for (j = 0; j < N; j++)
	{
		printf("%4.1f\t", aver2[j]);
	}
	printf("\n");
}