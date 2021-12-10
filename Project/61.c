#include <stdio.h>

int main()
{
	int stick;
	int day = 1;

	scanf("%d", &stick);
	
	for (;;)
	{
		if (stick != 1)
		{
			stick = stick / 2;
			day++;
		}
		else
		{
			break;
		}
	}

	printf("%d", day);

	return 0;
}