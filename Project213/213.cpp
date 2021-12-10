#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct competition
{
	int start;
	int finish;
}COMPETITION;

int n, cnt = 0;
COMPETITION com[1000010], temp;
bool cmp(COMPETITION x, COMPETITION y);

void RecursiveActivitySelection(int flag);

int main()
{
	com[0].start = 0, com[0].finish = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &com[i].start, &com[i].finish);
	}

	sort(com, com + n + 1, cmp);

	RecursiveActivitySelection(0);

	printf("%d", cnt);

	return 0;
}
void RecursiveActivitySelection(int flag)
{
	int m = flag + 1;

	while (m <= n && com[m].start < com[flag].finish)
	{
		m++;
	}
	if (m <= n)
	{
		cnt++;
		RecursiveActivitySelection(m);
	}
	else
	{
		return;
	}
}
bool cmp(COMPETITION x, COMPETITION y)
{
	return x.finish <= y.finish;
}