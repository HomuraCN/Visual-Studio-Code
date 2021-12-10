#include <stdio.h>

int main()
{
	typedef int Number;
	typedef int Group;

	Number one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve;
	Group first, second, third;

	printf("Please enter first group of one digit:");
	scanf_s("%d", &first);
	printf("Please enter second group of five digit:");
	scanf_s("%d", &second);
	printf("Please enter third group of five digit:");
	scanf_s("%d", &third);

	one = first;
	two = second / 10000 % 10;
	three = second / 1000 % 10;
	four = second / 100 % 10;
	five = second / 10 % 10;
	six = second % 10;
	seven = third / 10000 % 10;
	eight = third / 1000 % 10;
	nine = third / 100 % 10;
	ten = third / 10 % 10;
	eleven = third / 1 % 10;

	twelve = 9 - ((((one + three + five + seven + nine + eleven) * 3 + (two + four + six + eight + ten)) - 1) % 10);

	printf("Check digit:%d", twelve);

	return 0;
}