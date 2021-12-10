#include <stdio.h>

int head = 1, tail = 1;

void EnQueue(int Q[], int x, int M);
void DeQueue(int Q[], int M);

int main()
{
	int x, cnt = 0, flag = 0, M, N, Q[110];

	scanf("%d %d", &M, &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &x);
		for (int i = 1; i <= M; i++)
		{
			if (Q[i] == x)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cnt++;
			EnQueue(Q, x, M);
		}
		flag = 0;
	}
	/*
	for (int i = 1; i <= M; i++)
	{
		printf("%d ", Q[i]);
	}
	*/

	printf("%d", cnt);

	return 0;
}
void EnQueue(int Q[], int x, int M)
{
	int temp1 = head, temp2 = tail;
	Q[tail] = x;
	if (tail == M)
	{
		tail = 1;
	}
	else
	{
		tail++;
	}
	if (temp2 + 1 == temp1)
	{
		DeQueue(Q, M);
	}
}
void DeQueue(int Q[], int M)
{
	int x = Q[head];
	if (head == M)
	{
		head = 1;
	}
	else
	{
		head++;
	}
}