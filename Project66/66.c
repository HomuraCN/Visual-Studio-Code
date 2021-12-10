#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void PrintInfo(void);
void GetInputs(float *a, float *b, int *n);
void SimOneGame(float *proA, float *proB, int *scoreA, int *scoreB);
void SimNGames(float *proA, float *proB, int *scoreA, int *scoreB, int *winA, int *winB, int n);
int GameOver(int *scoreA, int *scoreB);
void PrintSummary(int winA, int winB, int n);

int main(void)
{
	int n = 0;
	int scoreA = 0, scoreB = 0, winA = 0, winB = 0;
	float proA, proB;
	srand(time(0));
	PrintInfo();
	GetInputs(&proA, &proB, &n);
	SimNGames(&proA, &proB, &scoreA, &scoreB, &winA, &winB, n);
	PrintSummary(winA, winB, n);

	return 0;
}

/* 输入程序信息 */
void PrintInfo(void)
{
	printf("这个程序模拟两个球员A&B的某种球类比赛\n");
	printf("程序运行时需要输入A&B的能力值(以0~1之间的小数表示)\n");
}

/*输入能力值*/
void GetInputs(float *a, float *b, int *n)
{
	printf("请输入球员A的能力值(0~1):");
	scanf("%f", a);
	printf("请输入球员B的能力值(0~1):");
	scanf("%f", b);
	printf("请输入模拟比赛的场次:");
	scanf("%d", n);
}

/*输出比赛结果*/
void PrintSummary(int winA, int winB, int n)
{
	n = winA + winB;
	printf("分析开始，共模拟%d场比赛\n", n);
	printf("球员A获胜%d场比赛，占比%.1f\n", winA, 1.0 * winA / n);
	printf("球员B获胜%d场比赛，占比%.1f\n", winB, 1.0 * winB / n);
}

/*模拟一场比赛*/
void SimOneGame(float *proA, float *proB, int *scoreA, int *scoreB)
{
	char serving = 'A';
	while (!GameOver(scoreA, scoreB))
	{
		if (serving == 'A')
			if (rand() / (RAND_MAX + 1.0) < (*proA))
				*scoreA += 1;
			else
				serving = 'B';
		else
			if (serving == 'B')
				if (rand() / (RAND_MAX + 1.0) < (*proB))
					*scoreB += 1;
				else
					serving = 'A';
			
	}
}

/*比赛结果*/
int GameOver(int *scoreA, int *scoreB)
{
	if (*scoreA == 15 || *scoreB == 15)
		return 1;
	else
		return 0;
}

/*模拟n场比赛*/
void SimNGames(float *proA, float *proB, int *scoreA, int *scoreB, int *winA, int *winB, int n)
{
	for (int i = 0; i < n; i++)
	{
		SimOneGame(proA, proB, scoreA, scoreB);
		if (*scoreA > *scoreB)
			*winA += 1;
		else
			*winB += 1;
	}
}