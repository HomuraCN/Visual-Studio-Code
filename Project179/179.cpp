#include <stdio.h>
#include <math.h>

int main()
{
	long long n, temp, sum = 0, flag = 0, stone[310] = { 0 };

	scanf("%lld", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &stone[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (stone[j] < stone[j + 1])
			{
				temp = stone[j];
				stone[j] = stone[j + 1];
				stone[j + 1] = temp;
			}
		}
	}

	long long* pLeft = stone, * pRight = stone + n;

	while (pLeft < pRight)
	{
		sum += pow((*pLeft - *pRight), 2);

		if (flag == 0)
		{
			pRight--;
			flag = 1;
		}
		else if (flag == 1)
		{
			pLeft++;
			flag = 0;
		}
	}

	printf("%lld", sum);

	return 0;
}