#include <stdio.h>

#define N 40

int ReadScore(int a[]);
void SortScore(int a[], int n[]);
void printfScore(int a[], int n[]);

int main(void)
{
	int score[N], n;
	n = ReadScore(score);
	printf("Total students are:%d\n", n);
	SortScore(score, n);
	printf("Sorted Scores:");
	PrintfScore(score, n);

	return 0;
}

/*函数功能: 输入n个学生某门课的成绩*/
int ReadScore(int a[])
{
	int i = -1;
	printf("Input scores:");
	return i;
}