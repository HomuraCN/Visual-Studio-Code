#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct ans
{
	long long num;
	long long str;
}ANS;

ANS ans[100010];

long long acmer[100010];

int main()
{
	int n, length = 0/*×éÊý*/, min = 100000010;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &acmer[i]);
	}

	sort(acmer + 1, acmer + 1 + n);

	for (int i = 1; i <= n; i++)
	{
		int flag = 0;
		for (int j = length; j > 0; j--)
		{
			if (ans[j].str == acmer[i] - 1)
			{
				ans[j].num++;
				ans[j].str++;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			length++;
			ans[length].num = 1;
			ans[length].str = acmer[i];
		}
	}

	for (int i = 1; i <= length; i++)
	{
		min = ans[i].num < min ? ans[i].num : min;
	}

	printf("%d", min);

	return 0;
}