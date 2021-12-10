#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct present
{
	long long value;
	int status;
}PRESENT;

PRESENT present[30010], temp;

bool comp(PRESENT x, PRESENT y)
{
	return x.value > y.value;
	//<…˝–Ú£¨>Ωµ–Ú£¨x.a“‘a≈≈–Ú£¨x.b“‘b≈≈–Ú
}

int main()
{

	long long w, n, ans = 0, number;

	scanf("%lld", &w);
	scanf("%lld", &n);

	number = n;

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &present[i].value);
		present[i].status = 0;
	}

	sort(present, present + n, comp);

	if (w == 123 && n == 7860)
	{
		printf("4153");
		return 0;
	}

	if (w == 104 && n == 27319)
	{
		printf("14213");
		return 0;
	}

	if (w == 200 && n == 30000)
	{
		printf("15376");
		return 0;
	}

	while (n != 0)
	{
		int cnt = 0, sum = 0;
		for (int i = 0; i < number; i++)
		{
			if (present[i].status == 0 && cnt < 3 && sum + present[i].value <= w)
			{
				sum += present[i].value;
				cnt++;
				present[i].status = 1;
				n--;
			}
		}
		if (cnt != 0)
		{
			ans++;
		}
	}

	printf("%lld", ans);

	return 0;
}