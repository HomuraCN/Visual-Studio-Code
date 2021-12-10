#include <stdio.h>

int main()
{
	int cnt = 0, point, height[100001];

	scanf("%d", &point);

	for (int i = 0; i < point; i++)
	{
		scanf("%d", &height[i]);
	}

	for (int i = 2; i < point; i++)
	{
		if (height[i] < height[i - 1])
		{
			int flag = i + 1;
			while (flag != point)
			{
				if (height[i] < height[flag])
				{
					cnt++;
					break;
				}
				else if (height[i] > height[flag])
				{
					break;
				}
				else
				{
					flag++;
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}