#include <stdio.h>
#include <queue>
using namespace std;

void BFS(int A);

int N, K[210], construction[210] = { 0 }, flag[210] = { 0 };

int main()
{
	int A, B;

	scanf("%d %d %d", &N, &A, &B);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &K[i]);
	}

	BFS(A);

	if (flag[B] == 1)
	{
		printf("%d", construction[B]);
	}
	else
	{
		printf("-1");
	}

	return 0;
}
void BFS(int A)
{
	int Now, Next;
	queue<int> Q;
	flag[A] = 1;
	Q.push(A);

	while (!Q.empty())
	{
		Now = Q.front();
		Q.pop();
		if (Now + K[Now] <= N && flag[Now + K[Now]] == 0)
		{
			Next = Now + K[Now];
			flag[Next] = 1;/*Í¿»Ò*/
			construction[Next] = construction[Now] + 1;
			Q.push(Next);
		}
		if (Now - K[Now] >= 1 && flag[Now - K[Now]] == 0)
		{
			Next = Now - K[Now];
			flag[Next] = 1;/*Í¿»Ò*/
			construction[Next] = construction[Now] + 1;
			Q.push(Next);
		}
		flag[Now] = 1;
	}
}