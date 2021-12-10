#include <stdio.h>

int main()
{
	int quantity;
	char pl[10];

	scanf_s("%d", &quantity);

	if (quantity > 0)
	{
		char pl[10] = { 'a', 'p', 'p', 'l', 'e', 's' };
		printf("Today, I ate %d %s.", quantity, pl);
	}
	else
	{
		char pl[10] = { 'a', 'p', 'p', 'l', 'e'};
		printf("Today, I ate %d %s.", quantity, pl);
	}

	return 0;
}