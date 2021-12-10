#include <stdio.h>

/*学生结构体*/
typedef struct student
{
	int id;
	int score1;
	int score2;
	double score3;
}STUDENT;

void Judge(STUDENT stu[], int n);

int main()
{
	STUDENT stu[1000];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &stu[i].id, &stu[i].score1, &stu[i].score2);
		stu[i].score3 = stu[i].score1 * 0.7 + stu[i].score2 * 0.3;
	}

	Judge(stu, n);

	return 0;
}

/*判断优秀*/
void Judge(STUDENT stu[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((stu[i].score1 + stu[i].score2) > 140 && stu[i].score3 >= 80)
		{
			printf("Excellent\n");
		}
		else
		{
			printf("Not excellent\n");
		}
	}
}