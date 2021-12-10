#include <stdio.h>
#include <algorithm>
using namespace std;

struct Attack
{
	int damage;
	int stage = 0;
};

bool cmp(struct Attack x, struct Attack y)
{
	return x.damage < y.damage;
}

int M, N, cnt = 0, sum = 0;
struct Attack attack[100010], armor[100010];

int main()
{
	
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &armor[i].damage);
		armor[i].stage = 0;
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &attack[i]);
		attack[i].stage = 0;
	}

	sort(armor, armor + M, cmp);
	sort(attack, attack + N, cmp);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (attack[j].stage == 0 && armor[i].damage < attack[j].damage)
			{
				cnt++;
				attack[j].stage = 1;
				armor[i].stage = 1;
				break;
			}
		}
	}

	if (cnt < M)
	{
		printf("0");
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (attack[i].stage == 0)
			{
				sum += attack[i].damage;
			}
		}

		printf("%d", sum);
	}

	return 0;
}