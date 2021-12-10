#include <stdio.h>
#include <queue>
using namespace std;

int n, k, a[1000010];
deque<int> DQ;

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	/*单调增队列*/
	for (int i = 1; i <= n; i++)
	{
		while (!DQ.empty() && a[DQ.back()] > a[i])
		{
			DQ.pop_back();
		}
		DQ.push_back(i);
		if (i >= k)/*窗口初始化结束*/
		{
			while (!DQ.empty() && DQ.front() <= i - k)
			{
				DQ.pop_front();
			}
			printf("%d ", a[DQ.front()]);
		}
	}

	printf("\n");
	while (!DQ.empty())
	{
		DQ.pop_front();
	}

	/*单调减队列*/
	for (int i = 1; i <= n; i++)
	{
		while (!DQ.empty() && a[DQ.back()] < a[i])
		{
			DQ.pop_back();
		}
		DQ.push_back(i);
		if (i >= k)
		{
			while (!DQ.empty() && DQ.front() <= i - k)
			{
				DQ.pop_front();
			}
			printf("%d ", a[DQ.front()]);
		}
	}

	return 0;
}