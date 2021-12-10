#include <stdio.h>
#include <stack>
using namespace std;

int q, n, pushed[100010], poped[100010];

int main()
{
	scanf("%d", &q);

	for (int i = 0; i < q; i++)
	{
		stack<int> S;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &pushed[j]);
		}
		for (int k = 1; k <= n; k++)
		{
			scanf("%d", &poped[k]);
		}
		int cnt = 1;
		for (int h = 1; h <= n; h++)
		{
			S.push(pushed[h]);
			while (!S.empty() && S.top() == poped[cnt])
			{
				S.pop();
				cnt++;
			}
		}
		if (S.empty())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}