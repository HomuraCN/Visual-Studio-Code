#include <stdio.h>
#include <math.h>

void Rec(int n, int i, int a, int b, int acid[], int bitter[]);

int ans = 100000000;

int main()
{
	int n, acid[11], bitter[11];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &acid[i], &bitter[i]);
	}

	Rec(n, 1, 1, 0, acid, bitter);

	printf("%d", ans);

	return 0;
}
void Rec(int n, int i, int a, int b, int acid[], int bitter[])
{
	if (i > n)
	{
		if (a == 1 && b == 0)return;

		ans = ans > abs(a - b) ? abs(a - b) : ans;
		return;
	}

	Rec(n, i + 1, a * acid[i], b + bitter[i], acid, bitter);
	Rec(n, i + 1, a, b, acid, bitter);

}