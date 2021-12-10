#include <stdio.h>

int main()
{
	int start, end, temp, zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;

	scanf("%d %d", &start, &end);

	for (int i = start; i <= end; i++)
	{
		temp = i;
		do
		{
			switch (temp % 10)
			{
			case 0: zero++; break;
			case 1: one++; break;
			case 2: two++; break;
			case 3: three++; break;
			case 4: four++; break;
			case 5: five++; break;
			case 6: six++; break;
			case 7: seven++; break;
			case 8: eight++; break;
			case 9: nine++; break;
			default: zero += 0;
			}
			temp /= 10;
		} while (temp != 0);
	}

	printf("%d %d %d %d %d %d %d %d %d %d", zero, one, two, three, four, five, six, seven, eight, nine);

	return 0;
}