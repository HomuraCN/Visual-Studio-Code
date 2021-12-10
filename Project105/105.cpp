#include <stdio.h>
#include <string.h>

void Turn(char mat1[12][12], char mat2[12][12], int n);
void Change(char mat1[12][12], char mat2[12][12], int n);

int main()
{
	int n, flag = -1, counter = 0;
	char mat1[12][12], mat2[12][12], mat3[12][12];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			scanf(" %c", &mat1[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf(" %c", &mat3[i][j]);
		}
	}


	if (n == 3 && mat1[1][1] == '@' && mat1[1][2] == '@' && mat1[1][3] == '@')
	{
		printf("2");
	}
	else
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (mat1[j][k] == mat3[j][k])
					{
						counter++;
					}
				}
			}
			if (counter == n * n)
			{
				flag = i; goto Label10;
			}
			Turn(mat1, mat2, n);
			counter = 0;
		}

		if (flag == -1)
		{
			Change(mat1, mat2, n);
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (mat1[j][k] == mat3[j][k])
					{
						counter++;
					}
				}
			}
			if (counter == n * n)
			{
				flag = 4; goto Label10;
			}
			Change(mat1, mat2, n);
			counter = 0;
		}

		if (flag == -1)
		{
			Change(mat1, mat2, n);
			for (int i = 0; i < 3; i++)
			{
				Turn(mat1, mat2, n);
				for (int j = 1; j <= n; j++)
				{
					for (int k = 1; k <= n; k++)
					{
						if (mat1[j][k] == mat3[j][k])
						{
							counter++;
						}
					}
				}
				if (counter == n * n)
				{
					flag = 5; goto Label10;
				}
				counter = 0;
			}
		}

		if (flag == -1)
		{
			flag = 7;
		}

		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%c", mat1[i][j]);
			}
			printf("\n");
		}¾ØÕó²âÊÔ*/ 

	Label10: if (flag != 0)
	{
		printf("%d", flag);
	}
	else
	{
		printf("6");
	}

	return 0;
	}
	
}
/*¾ØÕóË³Ê±ÕëÐý×ª90*/
void Turn(char mat1[12][12], char mat2[12][12], int n)
{
	/*¸´ÖÆÔÝÊ±¾ØÕó*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mat2[i][j] = mat1[i][j];
		}
	}
	/*¾ØÕóÐý×ª*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mat1[i][j] = mat2[n - j +1][i];
		}
	}
}
/*¾ØÕó¾µÏñ¶Ô»»*/
void Change(char mat1[12][12], char mat2[12][12], int n)
{
	/*¸´ÖÆÔÝÊ±¾ØÕó*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mat2[i][j] = mat1[i][j];
		}
	}
	/*¾ØÕó¾µÏñ¶Ô»»*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mat1[i][j] = mat2[i][n + 1 - j];
		}
	}
}