#include <stdio.h>
#include <string.h>

int main()
{
	int n, op;
	char str1[10000], str2[10000];

	scanf("%d %s", &n, str1);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%s", str2);
			strcat(str1, str2);
			printf("%s\n", str1);
		}
		else if (op == 2)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			str1[a + b] = '\0';
			strcpy(str2 , &str1[a]);
			strcpy(str1, str2);
			printf("%s\n", str1);
		}
		else if (op == 3)
		{
			int a;
			scanf("%d %s", &a, str2);
			strcat(str2, &str1[a]);
			str1[a] = '\0';
			strcat(str1, str2);
			printf("%s\n", str1);
		}
		else if (op == 4)
		{
			scanf("%s", str2);
			char* ans = strstr(str1, str2);
			if (ans != NULL)
			{
				printf("%d\n", int(ans - str1));
			}
			else
			{
				printf("%d\n", -1);
			}
		}
	}

	return 0;
}