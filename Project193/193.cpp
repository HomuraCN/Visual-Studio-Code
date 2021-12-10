#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long Partition(int left, int right, int i);

long long line[100100];
long long m, n, ans, score;

int main()
{
	scanf("%lld %lld", &m, &n);

	for (int i = 1; i <= m; i++)
	{
		scanf("%lld", &line[i]);
	}

	sort(line + 1, line + m + 1);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &score);
		ans += Partition(1, m, i);
	}

	printf("%lld", ans);

	return 0;
}

long long Partition(int left, int right, int i)
{
	int min, mid = (left + right) / 2;
	if (left == right)
	{
		min = abs(line[left] - score);
		if (abs(line[left + 1] - score) < min)
		{
			min = abs(line[left + 1] - score);
		}
		if (abs(line[left - 1] - score) < min)
		{
			min = abs(line[left - 1] - score);
		}

		return min;
	}
	else if (line[mid] <= score)
	{
		Partition(mid + 1, right, i);
	}
	else if (line[mid] > score)
	{
		Partition(left, mid - 1, i);
	}
}