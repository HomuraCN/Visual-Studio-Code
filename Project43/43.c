#include <stdio.h>

int main()
{
	int one, two, three, four, five, six, seven, eight, nine, ten, ID;
	char ch1, ch2, ch3;

	scanf_s("%d%c%d%d%d%c%d%d%d%d%d%c%d", &one, &ch1,&two, &three, &four, &ch2, &five, &six, &seven, &eight, &nine, &ch3, &ten);

	ID = one * 1 + two * 2 + three * 3 + four * 4 + five * 5 + six * 6 + seven * 7 + eight * 8 + nine * 9;

	if (ten == ID)
	{
		printf("Right");
	}
	else
	{
		printf("%d-%d%d%d-%d%d%d%d%d-%d", one, two, three, four, five, six, seven, eight, nine, ID);
	}

	return 0;
}