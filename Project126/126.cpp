#include <stdio.h>
#include <algorithm>
using namespace std;

void Rec(int n, int cnt, int origin, int num[], int end);

int Num[4], sum = 0, counter = 0;

int main()
{
	int n, num[10001];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
	}

	Rec(n, 0, 1, num, n - 4 + 1);

	printf("%d", counter);

	return 0;
}
void Rec(int n, int cnt, int origin, int num[], int end)
{
	if (cnt == 4)
	{
		sort(Num, Num+4);
		if (Num[0] + Num[1] == Num[2] && Num[2] == Num[3])
		{
			counter++;
			for (int i = 0; i < 4; i++)
			{
				printf("%3d", Num[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int i = origin; i <= end; i++)
	{
		Num[cnt] = num[i];
		Rec(n, cnt + 1, i + 1, num, end + 1);
	}
	return;
}