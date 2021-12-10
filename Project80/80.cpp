#include <stdio.h>

void TenToTwoToNine(int n, int m, int num[]);
void TenToElevenToSixteen(int n, int m, char Num[]);

int main(void)
{
	int i, n, m, temp, num[50];
	char Num[50];

	do
	{
		printf("������һ��ʮ��������<-1��������>");
		scanf("%d", &n);

		if (n == -1)
		{
			return 0;
		}

		printf("������Ҫת���ɵĽ���:");
		scanf("%d", &m);

		temp = n;

		for (i = 0; ; i++)
		{
			temp /= m;
			if (temp == 0)
			{
				break;
			}
		}

		if (m >= 2 && m <= 9)
		{
			TenToTwoToNine(n, m, num);

			printf("ת�����Ϊ:");
			for (int j = i; j >= 0; j--)
			{
				printf("%d", num[j]);
			}
			printf("\n");
		}
		else
		{
			TenToElevenToSixteen(n, m, Num);

			printf("ת�����Ϊ:");
			for (int k = i; k >= 0; k--)
			{
				printf("%c", Num[k]);
			}
			printf("\n");
		}
	} while (1);

	return 0;
}

/*ʮ����ת��2~9����*/
void TenToTwoToNine(int n, int m, int num[])
{
	int i = -1;

	do
	{
		i++;
		num[i] = n % m;
		n /= m;
	} while (n != 0);
}

/*ʮ����ת��11~16����*/
void TenToElevenToSixteen(int n, int m, char Num[])
{
	int i = -1;
	char ch[17] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	do
	{
		i++;
		Num[i] = ch[n % m];
		n /= m;
	} while (n != 0);
}