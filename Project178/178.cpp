#include <stdio.h>

typedef struct milk
{
	long long price;
	long long number;
}MILK;

MILK milk[5000], temp;

int main()
{
	int n, m;
	long long price = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &milk[i].price, &milk[i].number);
	}

	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < m - 1 - i; j++)
		{
			if (milk[j].price > milk[j + 1].price)
			{
				temp = milk[j];
				milk[j] = milk[j + 1];
				milk[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (n >= milk[i].number)
		{
			price += milk[i].price * milk[i].number;
			n -= milk[i].number;
		}
		else
		{
			price += milk[i].price * n;
			break;
		}
	}

	printf("%lld", price);

	return 0;
}