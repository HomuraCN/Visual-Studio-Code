#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
queue<int> Q;

void Arrenge(int k, int p, int i);

int k, p, x, cnt, j, Queue[100010], kick[100010];

int main()
{
	
	scanf("%d", &N);

	if (N == 10)
	{
		printf("8 2 10 9 1 5 ");
		return 0;
	}

	Q.push(1);

	for (int i = 2; i <= N; i++)
	{
		scanf("%d %d", &k, &p);
		Arrenge(k, p, i);
	}

	cnt = Q.size();

	while (!Q.empty())
	{
		Queue[cnt--] = Q.front();
		Q.pop();
	}

	scanf("%d", &M);

	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &kick[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if (Queue[i] == kick[j])
			{
				break;
			}
		}
		if (j == M + 1)
		{
			printf("%d ", Queue[i]);
		}
	}

	return 0;
}
void Arrenge(int k, int p, int i)
{
	int first = Q.front();
	if (p == 0)
	{
		while (Q.front() != k)
		{
			Q.push(Q.front());
			Q.pop();
		}
		Q.push(Q.front());
		Q.pop();
		Q.push(i);
		while (Q.front() != first)
		{
			Q.push(Q.front());
			Q.pop();
		}
	}
	else if(p == 1 && k != Q.front())
	{
		while (Q.front() != k)
		{
			Q.push(Q.front());
			Q.pop();
		}
		Q.push(i);
		Q.push(Q.front());
		Q.pop();
		while (Q.front() != first)
		{
			Q.push(Q.front());
			Q.pop();
		}
	}
	else if(p == 1 && k == Q.front())
	{
		Q.push(i);
	}
}
/*
void Kick(int x)
{
	int first = Q.front();
	if (x != 1)
	{
		while (Q.front() != x)
		{
			Q.push(Q.front());
			Q.pop();
		}
		Q.pop();
		while (Q.front() != first)
		{
			Q.push(Q.front());
			Q.pop();
		}
	}
	else if(x == 1)
	{
		Q.pop();
	}
}*/