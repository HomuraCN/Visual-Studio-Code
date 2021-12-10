#include <stdio.h>
#include <algorithm>
using namespace std;

int n, d, cnt = 0, cow[1000010] = { 0 }, position[1000010];

int main()
{
	scanf("%d %d", &n, &d);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &position[i]);
		cow[position[i]] = 1;
	}

	sort(position, position + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = position[i] + 1; j <= position[i] + d; j++)
		{
			if (cow[j] == 1)
			{
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}