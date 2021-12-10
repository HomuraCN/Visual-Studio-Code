#include <stdio.h>
#include <string.h>

int main()
{
	int length1, length2, counter = 0, count = 0;
	char str1[100], str2[10];

	gets_s(str1);
	gets_s(str2);

	length1 = strlen(str1);
	length2 = strlen(str2);

	for (int i = 0; i < length1; i++)
	{
		if (str1[i] == str2[0])
		{
			for (int j = i, k = 0; k < length2; j++, k++)
			{
				if (str1[j] = str2[k])
				{
					counter++;
				}
			}
			if (counter == length2)
			{
				count++;
			}
			counter = 0;
		}
	}

	printf("%s ³öÏÖ %d´Î", str2, count);

	return 0;
}