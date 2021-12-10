#include <stdio.h>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
priority_queue<int, vector<int>, greater<int>>heap;
int n, s;
int a[N];
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		heap.push(a[i]);
	}
	int ans = -1e9+10;
	for (int i = 1; i <= n; i++)
	{
		int t = heap.top();
		if (a[i] == t)
		{
			heap.pop();
			t = heap.top();
		}
		t = heap.top()-i * s;
		int res = a[i] + (n - 1) * s;
		res = min(res, t);
		ans = max(ans, res);
		heap.push(res);
	}
	printf("%d\n", ans);
}
