#include <stdio.h>
#include <string.h>

int main()
{
	int len1, len2, len3, len4, num[26] = { 0 }, max = -1, k, h, a = 0;
	char str1[101], str2[101], str3[101], str4[101];

	gets_s(str1); len1 = strlen(str1);
	gets_s(str2); len2 = strlen(str2);
	gets_s(str3);	len3 = strlen(str3);
	gets_s(str4);	len4 = strlen(str4);

	/*str1*/
	for (int i = 0; i < len1; i++)
	{
		switch (str1[i])
		{
		case'A': num[0]++; break;
		case'B': num[1]++; break;
		case'C': num[2]++; break;
		case'D': num[3]++; break;
		case'E': num[4]++; break;
		case'F': num[5]++; break;
		case'G': num[6]++; break;
		case'H': num[7]++; break;
		case'I': num[8]++; break;
		case'J': num[9]++; break;
		case'K': num[10]++; break;
		case'L': num[11]++; break;
		case'M': num[12]++; break;
		case'N': num[13]++; break;
		case'O': num[14]++; break;
		case'P': num[15]++; break;
		case'Q': num[16]++; break;
		case'R': num[17]++; break;
		case'S': num[18]++; break;
		case'T': num[19]++; break;
		case'U': num[20]++; break;
		case'V': num[21]++; break;
		case'W': num[22]++; break;
		case'X': num[23]++; break;
		case'Y': num[24]++; break;
		case'Z': num[25]++; break;
		default: num[0] += 0;
		}
	}
	/*str2*/
	for (int i = 0; i < len2; i++)
	{
		switch (str2[i])
		{
		case'A': num[0]++; break;
		case'B': num[1]++; break;
		case'	C': num[2]++; break;
		case'D': num[3]++; break;
		case'E': num[4]++; break;
		case'F': num[5]++; break;
		case'G': num[6]++; break;
		case'H': num[7]++; break;
		case'I': num[8]++; break;
		case'J': num[9]++; break;
		case'K': num[10]++; break;
		case'L': num[11]++; break;
		case'M': num[12]++; break;
		case'N': num[13]++; break;
		case'O': num[14]++; break;
		case'P': num[15]++; break;
		case'Q': num[16]++; break;
		case'R': num[17]++; break;
		case'S': num[18]++; break;
		case'T': num[19]++; break;
		case'U': num[20]++; break;
		case'V': num[21]++; break;
		case'W': num[22]++; break;
		case'X': num[23]++; break;
		case'Y': num[24]++; break;
		case'Z': num[25]++; break;
		default: num[0] += 0;
		}
	}
	/*str3*/
	for (int i = 0; i < len3; i++)
	{
		switch (str3[i])
		{
		case'A': num[0]++; break;
		case'B': num[1]++; break;
		case'C': num[2]++; break;
		case'D': num[3]++; break;
		case'E': num[4]++; break;
		case'F': num[5]++; break;
		case'G': num[6]++; break;
		case'H': num[7]++; break;
		case'I': num[8]++; break;
		case'J': num[9]++; break;
		case'K': num[10]++; break;
		case'L': num[11]++; break;
		case'M': num[12]++; break;
		case'N': num[13]++; break;
		case'O': num[14]++; break;
		case'P': num[15]++; break;
		case'Q': num[16]++; break;
		case'R': num[17]++; break;
		case'S': num[18]++; break;
		case'T': num[19]++; break;
		case'U': num[20]++; break;
		case'V': num[21]++; break;
		case'W': num[22]++; break;
		case'X': num[23]++; break;
		case'Y': num[24]++; break;
		case'Z': num[25]++; break;
		default: num[0] += 0;
		}
	}
	/*str4*/
	for (int i = 0; i < len4; i++)
	{
		switch (str4[i])
		{
		case'A': num[0]++; break;
		case'B': num[1]++; break;
		case'	C': num[2]++; break;
		case'D': num[3]++; break;
		case'E': num[4]++; break;
		case'F': num[5]++; break;
		case'G': num[6]++; break;
		case'H': num[7]++; break;
		case'I': num[8]++; break;
		case'J': num[9]++; break;
		case'K': num[10]++; break;
		case'L': num[11]++; break;
		case'M': num[12]++; break;
		case'N': num[13]++; break;
		case'O': num[14]++; break;
		case'P': num[15]++; break;
		case'Q': num[16]++; break;
		case'R': num[17]++; break;
		case'S': num[18]++; break;
		case'T': num[19]++; break;
		case'U': num[20]++; break;
		case'V': num[21]++; break;
		case'W': num[22]++; break;
		case'X': num[23]++; break;
		case'Y': num[24]++; break;
		case'Z': num[25]++; break;
		default: num[0] += 0;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
		}
	}

	for (k = 0; k < max; k++)
	{
		for (h = 0; h < 51; h+=2)
		{
			if (k >= (max - num[a++]))
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		a = 0;
		printf("\n");
	}

	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");

	return 0;
}