#include <stdio.h>
#include <math.h>

#define PI 3.141593

int main()
{
	int T;
	scanf_s("%d", &T);

	switch (T)
	{
	case 1:printf("I love Luogu!\n"); break;
	case 2:printf("%d %d\n", 6, 4); break;
	case 3:printf("%d\n%d\n%d\n", 3, 12, 2); break;
	case 4:printf("%.3f\n", 166.667); break;
	case 5:printf("%d\n", 15); break;
	case 6:printf("%f\n", sqrt(6 * 6 + 9 * 9)); break;
	case 7:printf("%d\n%d\n%d\n", 110, 90, 0); break;
	case 8:printf("%f\n%f\n%f\n", 2 * PI * 5, PI * 5 * 5, (4.0 / 3.0) * PI * 5 * 5 * 5); break;
	case 9:printf("%d\n", 22); break;
	case 10:printf("%d\n", 9); break;
	case 11:printf("%f\n", 33.4); break;
	case 12:printf("%d\n%c\n", 13, 'R'); break;
	case 13:printf("%f\n", pow(4.0 / 3.0 * PI * (1064), 1.0 / 3.0)); break;
	case 14:printf("%d\n", 50); break;
	}

	return 0;
}