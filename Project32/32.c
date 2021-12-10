#include <stdio.h>
#include <ctype.h>

int main()
{
	const char Cypher = '&';

	char orig, enpy;

	do
	{
		scanf_s("%c", &orig);
		enpy = orig ^ Cypher;
		if (iscntrl(orig) || iscntrl(enpy))
		{
			printf("%c", orig);
		}
		else
		{
			printf("%c", enpy);
		}
	} while (orig != EOF);

	return 0;
}