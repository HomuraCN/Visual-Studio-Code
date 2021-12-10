#include <stdio.h>
#include <ctype.h>

#define N 1000

int main(void)
{
	int i = 0, alpha = 0, space = 0, num = 0, otherCharacters = 0;
	char string[N];

	printf("Enter a string:");
	do
	{
		i++;
		scanf_s("%c", &string[i]);

		if (isalpha(string[i]))
		{
			alpha++;
		}
		else if (isspace(string[i]))
		{
			space++;
		}
		else if (isdigit(string[i]))
		{
			num++;
		}
		else
		{
			otherCharacters++;
		}

	} while (string[i] != '\n');

	printf("The number of alpha is %d\nThe number of space is %d\n", alpha, space);
	printf("The number of digit is %d\nThe number of other characters is %d\n", num, otherCharacters);

	return 0;
}
