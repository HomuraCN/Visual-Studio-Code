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

/*��������: ����n��ѧ��ĳ�ſεĳɼ�*/
int ReadScore(int a[])
{
	int i = -1;
	printf("Input scores:");
	return i;
}