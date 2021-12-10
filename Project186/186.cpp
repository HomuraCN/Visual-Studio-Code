#include <stdio.h>
#include <string.h>

void insert(char s1[], char s2[], char ch);

int main()
{
	char s1[100], s2[100], ch;

	gets_s(s1);
	gets_s(s2);
	scanf("%c", &ch);

	insert(s1, s2, ch);

	return 0;
}
void insert(char s1[], char s2[], char ch)
{
	int a = 0, len1 = strlen(s1), len2 = strlen(s2);
	char* p1 = s1;

	for (p1; p1 < s1 + len1; p1++)
	{
		char* p2 = s1 + len1 - 1, * p3 = p1; 

		if (*p1 == ch)
		{
			for (p2; p2 > p1; p2--)
			{
				*(p2 + len2) = *(p2);
			}
			for (p1++; p1 <= p3 + len2; p1++)
			{
				*p1 = s2[a++];
			}
			a = 0;
		}
		len1 = strlen(s1);
	}

	printf("%s", s1);
}