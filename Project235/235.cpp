#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Store
{
	int X;
	int F;
	int C;
	int price;
}STORE;

bool cmp(STORE x, STORE y)
{
	return x.price <= y.price;
}

int main()
{
	int K, E, N, num = 0, sum = 0;
	STORE store[110];

	scanf("%d %d %d", &K ,&E, &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &store[i].X, &store[i].F, &store[i].C);
		store[i].price = E - store[i].X + store[i].C;
	}

	sort(store + 1, store + N + 1, cmp);

	for (int i = 1; i <= N; i++)
	{
		if (store[i].F <= K - num)
		{
			sum += store[i].F * store[i].price;
			num += store[i].F;
		}
		else
		{
			sum += (K - num) * store[i].price;
			break;
		}
	}

	printf("%d", sum);

	return 0;
}