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

/* ���������Ϣ */
void PrintInfo(void)
{
	printf("�������ģ��������ԱA&B��ĳ���������\n");
	printf("��������ʱ��Ҫ����A&B������ֵ(��0~1֮���С����ʾ)\n");
}

/*��������ֵ*/
void GetInputs(float *a, float *b, int *n)
{
	printf("��������ԱA������ֵ(0~1):");
	scanf("%f", a);
	printf("��������ԱB������ֵ(0~1):");
	scanf("%f", b);
	printf("������ģ������ĳ���:");
	scanf("%d", n);
}

/*����������*/
void PrintSummary(int winA, int winB, int n)
{
	n = winA + winB;
	printf("������ʼ����ģ��%d������\n", n);
	printf("��ԱA��ʤ%d��������ռ��%.1f\n", winA, 1.0 * winA / n);
	printf("��ԱB��ʤ%d��������ռ��%.1f\n", winB, 1.0 * winB / n);
}

/*ģ��һ������*/
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

/*�������*/
int GameOver(int *scoreA, int *scoreB)
{
	if (*scoreA == 15 || *scoreB == 15)
		return 1;
	else
		return 0;
}

/*ģ��n������*/
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