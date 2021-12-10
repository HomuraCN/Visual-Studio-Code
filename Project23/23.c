#include <stdio.h>
#include <ctype.h>

int main()
{	
	char ch;
	scanf_s("%c", &ch);

	ch = tolower(ch);
	printf("%c", ch);

	return 0;
}